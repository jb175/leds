#ifndef SOFTBREATHING_H
#define SOFTBREATHING_H

#include <FastLED.h>
#include <vector>
#include <animations/Animation.h>

class Breathing : public Animation {
public:
    Breathing(CRGB color, unsigned long duration, unsigned int times) 
        : Animation(color, duration, times), halfDuration(duration / 2) {}

    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);

private:
    const uint8_t lowerBrightness = 0;// 50;  // Minimum brightness (not complete off)
    const uint8_t higherBrightness = 255; // Max brightness
    long halfDuration;
};

#endif
