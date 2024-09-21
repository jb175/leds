//with sound detector
#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN     18     // LED strip data pin
#define NUM_LEDS    60     // Number of LEDs
#define BRIGHTNESS  128    // Default brightness level
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

#define SOUND_PIN   34     // Pin where sound sensor A0 is connected
#define SOUND_THRESHOLD 50 // Threshold for sound sensitivity

CRGB leds[NUM_LEDS];

void setup() {
  // Initialize FastLED library
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  // Initialize sound sensor pin
  pinMode(SOUND_PIN, INPUT);
}

void loop() {
  // Read analog sound sensor value
  int soundValue = analogRead(SOUND_PIN);
  
  // Check if sound value exceeds threshold
  if (soundValue > SOUND_THRESHOLD) {
    // Turn LEDs green if sound is loud enough
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Green;
    }
  } else {
    // Default color
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Blue;
    }
  }

  // Show the LED colors
  FastLED.show();
  
  // Add a short delay
  delay(100);
}