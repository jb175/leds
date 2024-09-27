#include "SoftGlow.h"

SoftGlow::SoftGlow(CRGB color, unsigned long duration, float pulseShape, bool startAtFullBrightness) 
    : color(color), duration(duration), pulseShape(pulseShape), startAtFullBrightness(startAtFullBrightness) {}

std::vector<CRGB> SoftGlow::generateLEDs(int numLeds, unsigned long timeElapsed) {
    const uint8_t lowerBrightness = 0;
    const uint8_t higherBrightness = 255;
    std::vector<CRGB> ledStates(numLeds);

    // Calculate brightness to go from 0 to max light and back to 0
    float cyclePosition = fmod(timeElapsed, duration) / (float)duration;
    float adjustedCyclePosition = pow(cyclePosition, pulseShape);
    uint8_t brightness = (sin8(adjustedCyclePosition * 255) * (higherBrightness - lowerBrightness) / 255) + lowerBrightness;

    // Adjust brightness based on startAtFullBrightness
    if (startAtFullBrightness) {
        brightness = higherBrightness - brightness;
    }

    // Apply the color and brightness to each LED
    for (int i = 0; i < numLeds; i++) {
        ledStates[i] = color;
        ledStates[i].nscale8(brightness); // Adjust brightness
    }

    return ledStates;
}