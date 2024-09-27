#include "NoTransition.h"

NoTransition::NoTransition() : Transition(nullptr, nullptr, 0) {}

std::vector<CRGB> NoTransition::generateLEDs(int numLeds, unsigned long timeElapsed) {
    return std::vector<CRGB>();
}