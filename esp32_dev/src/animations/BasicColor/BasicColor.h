#ifndef BASICCOLOR_H
#define BASICCOLOR_H

#include <FastLED.h>
#include <vector>
#include <animations/Animation.h>

class BasicColor : public Animation {
public:
    BasicColor(CRGB color, unsigned long duration, unsigned int times) : Animation(color, duration, times) {};
    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);
};

#endif