#ifndef CALM_ANIMATION_H
#define CALM_ANIMATION_H

#include <animations/Animation.h>

class SoftAnimation : public Animation {
public:
    SoftAnimation(CRGB color, unsigned long duration) : Animation(color, duration) {
        this->setColor(color);
        this->setDuration(duration);
    };
};

#endif