#ifndef CALM_ANIMATION_H
#define CALM_ANIMATION_H

#include <animations/Animation.h>

class CalmAnimation : public Animation {
public:
    ~CalmAnimation() override = default;
    void generateLEDs(CRGB* leds, int numLeds, unsigned long timeElapsed) override = 0; // Generate the LED states
};

#endif // CALM_ANIMATION_H