#include "SlideTransition.h"

std::vector<CRGB> SlideTransition::generateLEDs(int numLeds, unsigned long timeElapsed) {
    std::vector<CRGB> fromLedStates = this->getFrom()->generateLEDs(numLeds, timeElapsed);
    std::vector<CRGB> toLedStates = this->getTo()->generateLEDs(numLeds, timeElapsed);
    std::vector<CRGB> ledStates(numLeds);

    unsigned long transitionElapsed = millis() - this->getStartTime(); // Time elapsed since the transition started
    unsigned int ledsToReplace = (transitionElapsed * numLeds) / this->getDuration(); // Number of LEDs to replace based on the transition progress

    if (direction!=0) {
        ledsToReplace = numLeds - ledsToReplace;
    }
    // Blend the from and to LED states
    for (int i = 0; i < numLeds; i++) {
        if (i < ledsToReplace) {
            if (direction!=0) {
                ledStates[i] = fromLedStates[i];
            } else {
                ledStates[i] = toLedStates[i];
            }
        } else {
            if (direction!=0) {
                ledStates[i] = toLedStates[i];
            } else {
                ledStates[i] = fromLedStates[i];
            }
        }
    }

    return ledStates;
}