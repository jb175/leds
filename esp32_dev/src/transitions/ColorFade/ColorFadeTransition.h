#ifndef COLOR_FADE_TRANSITION_H
#define COLOR_FADE_TRANSITION_H

#include <transitions/Transition.h>

class ColorFadeTransition : public Transition {
public:
    ColorFadeTransition(Animation *from, Animation *to, unsigned long duration) : Transition(from, to, duration) {};
    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);
};

#endif