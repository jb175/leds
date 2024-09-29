#ifndef SOFTBLINKINGSTARS_H
#define SOFTBLINKINGSTARS_H

#include <FastLED.h>
#include "SoftAnimation.h"

class SoftBlinkingStars : public SoftAnimation {
public:
    SoftBlinkingStars(CRGB color, unsigned long duration, unsigned int times) 
        : SoftAnimation(color, duration, times) {}

    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);

private:
    CRGB dimStarColor(CRGB color, uint8_t brightness);
};

#endif
