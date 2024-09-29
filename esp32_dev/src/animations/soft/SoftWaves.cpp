#include "SoftWaves.h"
#include <cmath>

std::vector<CRGB> SoftWaves::generateLEDs(int numLeds, unsigned long timeElapsed) {
    std::vector<CRGB> ledStates(numLeds);

    long elapsedTimeCycle = timeElapsed % this->getDuration();

    // Calculate the position of the dip based on elapsed time and direction
    float position = float(elapsedTimeCycle) / float(this->getDuration()) * numLeds;
    if (!direction) {
        position = numLeds - position;
    }

    for (int i = 0; i < numLeds; i++) {
        // Create a Gaussian dip effect
        float distance = fabs(i - position);
        float wave = exp(-pow(distance, 2) / (2 * pow(numLeds / 20.0, 2))); // Adjust the denominator to control the width of the dip
        uint8_t brightness = 255 - wave * 255; // Invert the wave to create a dip
        ledStates[i] = this->getColor();
        ledStates[i].nscale8(brightness);
    }

    return ledStates;
}