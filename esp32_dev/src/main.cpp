#include <Arduino.h>
#include <FastLED.h>
#include <animations/calm/SoftGlow.h>

#define NUM_LEDS 60
#define DATA_PIN 2
#define COLOR_INTERVAL 10000 // Time interval for each color in milliseconds
#define GLOW_INTERVAL 5000 // Time interval to transition from previous to new color in milliseconds

CRGB leds[NUM_LEDS];
SoftGlow* currentSoftGlow;
SoftGlow* previousSoftGlow;
unsigned long lastIntervalChange = 0;
CRGB lastColor;
CRGB currentColor;

std::vector<CRGB> colors = {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, CRGB::Purple, CRGB::Cyan, CRGB::Orange};

void setup() {
    FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS); // Set up the LED strip
    randomSeed(analogRead(0)); // Initialize random seed
    currentColor = colors[random(0, colors.size())];
    currentSoftGlow = new SoftGlow(currentColor, GLOW_INTERVAL); // Initialize with a random color
    previousSoftGlow = nullptr; // No previous glow initially
}

void loop() {
    unsigned long timeElapsed = millis(); // Get the elapsed time
    unsigned long intervalElapsed = timeElapsed % COLOR_INTERVAL; // Time elapsed within the current interval

    // Check if it's time to change the color
    if (timeElapsed - lastIntervalChange >= COLOR_INTERVAL) {
        CRGB newColor;
        do {
            newColor = colors[random(0, colors.size())];
        } while (newColor == currentColor || newColor == lastColor); // Ensure the new color is different from the current and last colors

        // Update the previous glow
        if (previousSoftGlow != nullptr) {
            delete previousSoftGlow; // Delete the old previous SoftGlow object
        }
        previousSoftGlow = currentSoftGlow; // Move current glow to previous

        // Create a new SoftGlow with the new color
        currentSoftGlow = new SoftGlow(newColor, GLOW_INTERVAL);
        lastColor = currentColor; // Update the last color
        currentColor = newColor; // Update the current color
        lastIntervalChange = timeElapsed; // Update the last interval change time
    }

    std::vector<CRGB> currentLedStates = currentSoftGlow->generateLEDs(NUM_LEDS, intervalElapsed); // Generate the current LED states
    std::vector<CRGB> previousLedStates(NUM_LEDS);

    if (previousSoftGlow != nullptr) {
        unsigned long transitionElapsed = timeElapsed - lastIntervalChange; // Time elapsed since the last interval change
        unsigned int ledsToReplace = (transitionElapsed * NUM_LEDS) / GLOW_INTERVAL; // Number of LEDs to replace based on the transition progress

        previousLedStates = previousSoftGlow->generateLEDs(NUM_LEDS, intervalElapsed); // Generate the previous LED states

        // Blend the previous and current LED states
        for (int i = 0; i < NUM_LEDS; i++) {
            if (i < ledsToReplace) {
                leds[i] = currentLedStates[i];
            } else {
                leds[i] = previousLedStates[i];
            }
        }
    } else {
        // If there's no previous glow, just use the current LED states
        for (int i = 0; i < NUM_LEDS; i++) {
            leds[i] = currentLedStates[i];
        }
    }

    FastLED.show(); // Display the LEDs
}