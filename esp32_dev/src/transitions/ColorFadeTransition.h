#ifndef COLOR_FADE_TRANSITION_H
#define COLOR_FADE_TRANSITION_H

#include <transitions/Transition.h>

class ColorFadeTransition : public Transition {
public:
    ColorFadeTransition(SoftAnimation *from, SoftAnimation *to, unsigned long duration);
    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);
};

#endif