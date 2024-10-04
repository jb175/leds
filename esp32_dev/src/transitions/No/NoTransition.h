#ifndef NO_TRANSITION_H
#define NO_TRANSITION_H

#include <transitions/Transition.h>

class NoTransition : public Transition {
public:
    NoTransition() : Transition(nullptr, nullptr, 0) {};
    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);
};

#endif