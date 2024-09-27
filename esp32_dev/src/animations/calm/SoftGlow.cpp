#include "SoftGlow.h"

SoftGlow::SoftGlow(CRGB color, unsigned long duration) 
    : color(color), duration(duration) {}

std::vector<CRGB> SoftGlow::generateLEDs(int numLeds, unsigned long timeElapsed) {
    const uint8_t lowerBrightness = 0;
    const uint8_t higherBrightness = 255;
    std::vector<CRGB> ledStates(numLeds);

    // Calculate the brightness based on the time elapsed
    uint8_t brightness;
    if (timeElapsed%duration < duration/2) {
        brightness = lowerBrightness + timeElapsed%duration * (higherBrightness - lowerBrightness) / (duration/2);
    } else {
        brightness = higherBrightness - (timeElapsed%duration - duration/2) * (higherBrightness - lowerBrightness) / (duration/2);
    }

    // Apply the color and brightness to each LED
    for (int i = 0; i < numLeds; i++) {
        ledStates[i] = color;
        ledStates[i].nscale8(brightness); // Adjust brightness
    }

    return ledStates;
}