#ifndef SOFTRAINBOWPULSE_H
#define SOFTRAINBOWPULSE_H

#include <FastLED.h>
#include "SoftAnimation.h"

class SoftRainbowPulse : public SoftAnimation {
public:
    SoftRainbowPulse(unsigned long duration, unsigned int times) 
        : SoftAnimation(CRGB::Black, duration, times) {}

    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);
};

#endif
