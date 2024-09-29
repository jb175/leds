#include "SoftGlow.h"

std::vector<CRGB> SoftGlow::generateLEDs(int numLeds, unsigned long timeElapsed) {
    checkIsFinished(timeElapsed);
    std::vector<CRGB> ledStates(numLeds);

    long elspsedTimeCycle = timeElapsed % this->getDuration();

    // Calculate the brightness based on the time elapsed
    uint8_t brightness;
    if (elspsedTimeCycle < this->getDuration()/2) {
        brightness = lowerBrightness + elspsedTimeCycle * (higherBrightness - lowerBrightness) / (halfDuration);
    } else {
        brightness = static_cast<uint8_t>(higherBrightness - (elspsedTimeCycle - halfDuration) * (higherBrightness - lowerBrightness) / (halfDuration));
    }

    // Apply the color and brightness to each LED
    for (int i = 0; i < numLeds; i++) {
        ledStates[i] = this->getColor();
        ledStates[i].nscale8(brightness); // Adjust brightness
    }

    return ledStates;
}