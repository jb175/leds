#include "SoftRainbowPulse.h"

std::vector<CRGB> SoftRainbowPulse::generateLEDs(int numLeds, unsigned long timeElapsed) {
    std::vector<CRGB> ledStates(numLeds);

    long elapsedTimeCycle = timeElapsed % this->getDuration();
    
    // Calculate hue based on elapsed time and loop it over 255 hues
    uint8_t hue = (255 * elapsedTimeCycle) / this->getDuration();

    for (int i = 0; i < numLeds; i++) {
        ledStates[i] = CHSV(hue, 255, 255); // Full saturation and brightness for vivid colors
    }

    return ledStates;
}
