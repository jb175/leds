#include "ColorFadeTransition.h"

/**
 * @brief Generates the LED states for the color fade transition.
 *
 * This function blends the LED states from the starting color to the ending color
 * based on the elapsed time of the transition.
 *
 * @param numLeds The number of LEDs to generate states for.
 * @param timeElapsed The time elapsed since the transition started.
 * @return A vector of CRGB objects representing the current LED states.
 */
std::vector<CRGB> ColorFadeTransition::generateLEDs(int numLeds, unsigned long timeElapsed) {
    std::vector<CRGB> ledStates(numLeds);

    std::vector<CRGB> fromLedStates = this->getFrom()->generateLEDs(numLeds, timeElapsed);
    std::vector<CRGB> toLedStates = this->getTo()->generateLEDs(numLeds, timeElapsed);

    unsigned long transitionElapsed = millis() - this->getStartTime();

    // Blend the from and to LED states
    for (int i = 0; i < numLeds; i++) {
        ledStates[i] = fromLedStates[i].lerp8(toLedStates[i], 255 * transitionElapsed / this->getDuration());
    }

    return ledStates;
}