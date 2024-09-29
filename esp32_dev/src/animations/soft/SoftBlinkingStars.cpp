#include "SoftBlinkingStars.h"

std::vector<CRGB> SoftBlinkingStars::generateLEDs(int numLeds, unsigned long timeElapsed) {
    std::vector<CRGB> ledStates(numLeds);

    // Randomly determine which LEDs blink softly
    for (int i = 0; i < numLeds; i++) {
        if (random(0, 100) < 10) { // 10% chance that a star blinks
            uint8_t brightness = random(50, 255); // Random brightness for stars
            ledStates[i] = dimStarColor(this->getColor(), brightness);
        } else {
            ledStates[i] = CRGB::Black; // No star, LED stays off
        }
    }

    return ledStates;
}

CRGB SoftBlinkingStars::dimStarColor(CRGB color, uint8_t brightness) {
    CRGB newColor = color;
    newColor.nscale8(brightness); // Adjust the brightness of the star
    return newColor;
}
