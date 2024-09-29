#include "SoftBreathing.h"

std::vector<CRGB> SoftBreathing::generateLEDs(int numLeds, unsigned long timeElapsed) {
    std::vector<CRGB> ledStates(numLeds);

    long elapsedTimeCycle = timeElapsed % this->getDuration();

    // Use a full sine wave for smooth breathing effect
    float wave = (sin(PI * 2 * (float(elapsedTimeCycle) / float(this->getDuration())) - PI/2) + 1.0) / 2.0;
    uint8_t brightness = lowerBrightness + wave * (higherBrightness - lowerBrightness);

    for (int i = 0; i < numLeds; i++) {
        ledStates[i] = this->getColor();
        ledStates[i].nscale8(brightness); // Scale brightness using sine wave
    }

    return ledStates;
}