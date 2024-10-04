#ifndef SLIDE_TRANSITION_H
#define SLIDE_TRANSITION_H

#include <transitions/Transition.h>

class SlideTransition : public Transition {
public:
    SlideTransition(Animation *from, Animation *to, unsigned long duration, long direction) 
        : Transition(from, to, duration), direction(direction) {}
    SlideTransition(Animation *from, Animation *to, unsigned long duration) 
        : Transition(from, to, duration), direction(random(0, 2)) {}
    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);
private:
    long direction;
};

#endif