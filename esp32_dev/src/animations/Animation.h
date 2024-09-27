#ifndef ANIMATION_H
#define ANIMATION_H

#include <Arduino.h>
#include <FastLED.h>

class Animation {
public:
    virtual ~Animation() = default;
    virtual void generateLEDs(CRGB* leds, int numLeds, unsigned long timeElapsed) = 0; // Generate the LED states
};

#endif // ANIMATION_H