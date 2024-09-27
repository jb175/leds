#ifndef SLIDE_TRANSITION_H
#define SLIDE_TRANSITION_H

#include <transitions/Transition.h>

class SlideTransition : public Transition {
public:
    SlideTransition(CalmAnimation *from, CalmAnimation *to, unsigned long duration);
    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);
};

#endif // TRANSITION_H