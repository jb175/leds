#ifndef ANIMATION_H
#define ANIMATION_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>

class Animation {
public:
    virtual ~Animation() = default;
    virtual std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed) = 0; // Generate the LED states
};

#endif // ANIMATION_H