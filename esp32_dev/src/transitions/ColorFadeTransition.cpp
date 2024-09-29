#include "ColorFadeTransition.h"

ColorFadeTransition::ColorFadeTransition(SoftAnimation* from, SoftAnimation* to, unsigned long duration) : Transition(from, to, duration) {}

std::vector<CRGB> ColorFadeTransition::generateLEDs(int numLeds, unsigned long timeElapsed) {
    std::vector<CRGB> fromLedStates = this->getFrom()->generateLEDs(numLeds, timeElapsed);
    std::vector<CRGB> toLedStates = this->getTo()->generateLEDs(numLeds, timeElapsed);
    std::vector<CRGB> ledStates(numLeds);

    unsigned long transitionElapsed = millis() - this->getStartTime(); // Time elapsed since the transition started

    // Blend the from and to LED states
    for (int i = 0; i < numLeds; i++) {
        ledStates[i] = fromLedStates[i].lerp8(toLedStates[i], 255 * transitionElapsed / this->getDuration());
    }

    return ledStates;
}