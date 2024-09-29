#ifndef ANIMATIONLIST_H
#define ANIMATIONLIST_H

#include <Arduino.h>
#include <FastLED.h>

class AnimationList {
public:
    virtual ~AnimationList() = default;
    virtual void createNewTransition() = 0;
    virtual void createNewAnimation() = 0;
    virtual void runAnimationList(CRGB* leds, int numLeds, unsigned long timeElapsed) = 0;
};

#endif