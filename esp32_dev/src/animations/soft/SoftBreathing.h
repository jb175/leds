#ifndef SOFTBREATHING_H
#define SOFTBREATHING_H

#include <FastLED.h>
#include <vector>
#include "SoftAnimation.h"

class SoftBreathing : public SoftAnimation {
public:
    SoftBreathing(CRGB color, unsigned long duration, unsigned int times) 
        : SoftAnimation(color, duration, times), halfDuration(duration / 2) {}

    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);

private:
    const uint8_t lowerBrightness = 0;// 50;  // Minimum brightness (not complete off)
    const uint8_t higherBrightness = 255; // Max brightness
    long halfDuration;
};

#endif
