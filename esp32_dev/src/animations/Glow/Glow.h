#ifndef SOFTGLOW_H
#define SOFTGLOW_H

#include <FastLED.h>
#include <vector>
#include <animations/Animation.h>

class Glow : public Animation {
public:
    Glow(CRGB color, unsigned long duration, unsigned int times) : Animation(color, duration, times), halfDuration(duration/2) {};
    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);
private:
    const uint8_t lowerBrightness = 0;
    const uint8_t higherBrightness = 255;
    long halfDuration;
};

#endif