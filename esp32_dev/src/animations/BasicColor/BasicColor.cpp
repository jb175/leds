#include "BasicColor.h"

std::vector<CRGB> BasicColor::generateLEDs(int numLeds, unsigned long timeElapsed) {
    std::vector<CRGB> ledStates(numLeds);

    for (int i = 0; i < numLeds; i++) {
        ledStates[i] = this->getColor();
    }

    return ledStates;
}