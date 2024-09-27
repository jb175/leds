#include <Arduino.h>
#include <FastLED.h>
#include <animations/calm/SoftGlow.h>

#define NUM_LEDS 60
#define DATA_PIN 2
#define COLOR_INTERVAL 5000 // Time interval for each color in milliseconds

CRGB leds[NUM_LEDS];
SoftGlow softGlowBlue(CRGB::Blue, 5000, 0.8, false);
SoftGlow softGlowRed(CRGB::Red, 5000, 0.8, false);
SoftGlow softGlowGreen(CRGB::Green, 5000, 0.8, false);

void setup() {
    FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS); // Set up the LED strip
}

void loop() {
    unsigned long timeElapsed = millis(); // Get the elapsed time
    unsigned long currentInterval = (timeElapsed / COLOR_INTERVAL) % 3; // Determine the current color interval
    std::vector<CRGB> ledStates;

    if (currentInterval == 0) {
        ledStates = softGlowBlue.generateLEDs(NUM_LEDS, timeElapsed); // Generate the LED states for blue
    } else if (currentInterval == 1) {
        ledStates = softGlowRed.generateLEDs(NUM_LEDS, timeElapsed); // Generate the LED states for red
    } else {
        ledStates = softGlowGreen.generateLEDs(NUM_LEDS, timeElapsed); // Generate the LED states for green
    }

    // Copy the generated LED states to the actual LED array
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ledStates[i];
    }

    FastLED.show(); // Display the LEDs
}