#include "SoftGlow.h"

SoftGlow::SoftGlow(CRGB color, unsigned long duration, float pulseShape, bool startAtFullBrightness) 
    : color(color), duration(duration), pulseShape(pulseShape), startAtFullBrightness(startAtFullBrightness) {}

void SoftGlow::generateLEDs(CRGB* leds, int numLeds, unsigned long timeElapsed) {
    const uint8_t lowerBrightness = 0;
    const uint8_t higherBrightness = 255;
    
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
        leds[i] = color;
        leds[i].nscale8(brightness); // Adjust brightness
    }
}