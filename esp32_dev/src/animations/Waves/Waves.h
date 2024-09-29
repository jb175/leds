#ifndef SOFTWAVES_H
#define SOFTWAVES_H

#include <FastLED.h>
#include <animations/Animation.h>

class Waves : public Animation {
public:
    Waves(CRGB color, unsigned long duration, unsigned int times, bool direction) 
        : Animation(color, duration, times), direction(direction) {}

    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);

private:
    bool direction; // true for forward, false for backward
};

#endif