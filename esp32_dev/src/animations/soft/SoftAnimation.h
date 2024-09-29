#ifndef CALM_ANIMATION_H
#define CALM_ANIMATION_H

#include <animations/Animation.h>

class SoftAnimation : public Animation {
public:
    SoftAnimation(CRGB color, unsigned long duration, unsigned int times) : Animation(color, duration, times) {};
};

#endif