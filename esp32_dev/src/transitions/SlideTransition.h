#ifndef SLIDE_TRANSITION_H
#define SLIDE_TRANSITION_H

#include <transitions/Transition.h>

class SlideTransition : public Transition {
public:
    SlideTransition(SoftAnimation *from, SoftAnimation *to, unsigned long duration, long direction) 
        : Transition(from, to, duration), direction(direction) {}
    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);
private:
    long direction;
};

#endif