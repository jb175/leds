#ifndef SOFTWAVES_H
#define SOFTWAVES_H

#include <FastLED.h>
#include "SoftAnimation.h"

class SoftWaves : public SoftAnimation {
public:
    SoftWaves(CRGB color, unsigned long duration, unsigned int times, bool direction) 
        : SoftAnimation(color, duration, times), direction(direction) {}

    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);

private:
    bool direction; // true for forward, false for backward
};

#endif