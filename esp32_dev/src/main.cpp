#include <Arduino.h>
#include <FastLED.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <animationLists/AnimationList.h>
#include <animationLists/Soft/SoftAnimationList.h>
#include <animationLists/AnimationTest/AnimationTestList.h>
#include <animationLists/TransitionTest/TransitionTestList.h>

// Define UUIDs for the service and characteristic
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

#define NUM_LEDS 60
#define DATA_PIN 13

BLECharacteristic *pCharacteristic;
bool deviceConnected = false;
const int ledPin = 13;  // GPIO pin where the LED is connected

bool power = true;

CRGB leds[NUM_LEDS];
AnimationList* animationList = new SoftAnimationList();

// Callback to handle changes in connection state
class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      Serial.println("Client connected");
    }

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
      Serial.println("Client disconnected");
    }
};

// Callback to handle writes to the characteristic (LED on/off control)
class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rxValue = pCharacteristic->getValue();
      
      if (rxValue.length() > 0) {
        Serial.print("Received Value: ");
        Serial.println(rxValue.c_str());
        
        // Convert the received value into an integer (0 = off, 1 = on)
        if (rxValue == "1") {
          power = true;
        } else if (rxValue == "0") {
          power = false;
        }
      }
    }
};

void setup() {
    // Initialize serial communication
    Serial.begin(115200);
    
    // Set the LED pin as output
    pinMode(ledPin, OUTPUT);
    
    // Create the BLE Device
    BLEDevice::init("ESP32 LED Controller");

    // Create the BLE Server
    BLEServer *pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks());

    // Create the BLE Service
    BLEService *pService = pServer->createService(SERVICE_UUID);

    // Create a BLE Characteristic
    pCharacteristic = pService->createCharacteristic(
                        CHARACTERISTIC_UUID,
                        BLECharacteristic::PROPERTY_READ |
                        BLECharacteristic::PROPERTY_WRITE |
                        BLECharacteristic::PROPERTY_NOTIFY
                        );

    pCharacteristic->setCallbacks(new MyCallbacks());

    // Start the service
    pService->start();

    // Start advertising
    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06);  // Help with power management
    pAdvertising->setMinPreferred(0x12);
    BLEDevice::startAdvertising();

    Serial.println("Waiting for a client to connect...");

    CFastLED::addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
    randomSeed(analogRead(0) + millis());
    animationList->createNewAnimation();
}

void loop() {
    static unsigned long lastUpdate = 0;
    unsigned long timeElapsed = millis();
    if (deviceConnected && power) {
        // Update the LED strip
        animationList->runAnimationList(leds, NUM_LEDS, timeElapsed);
        if (timeElapsed - lastUpdate >= 1000) {
            String animationData = "Current Animation: " + String(animationList->getCurrentAnimationName()) + "\n";
            animationData += "Parameters: " + String(animationList->getCurrentAnimationParams());
            pCharacteristic->setValue(animationData.c_str());
            pCharacteristic->notify();
            Serial.println("Sent notification: " + animationData); // Debugging statement
            lastUpdate = timeElapsed;
        }
    } else {
        for (auto& led : leds) {
            led = CRGB::Black;
        }
        FastLED.show();
    }
}