#ifndef CALM_ANIMATION_H
#define CALM_ANIMATION_H

#include <animations/Animation.h>

class CalmAnimation : public Animation {
public:
    CalmAnimation(CRGB color, unsigned long duration) : Animation(color, duration) {
        this->setColor(color);
        this->setDuration(duration);
    };
};

#endif