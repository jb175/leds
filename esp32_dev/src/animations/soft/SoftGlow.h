#ifndef SOFTGLOW_H
#define SOFTGLOW_H

#include <FastLED.h>
#include <vector>
#include <animations/soft/SoftAnimation.h>

class SoftGlow : public SoftAnimation {
public:
    SoftGlow(CRGB color, unsigned long duration, unsigned int times) : SoftAnimation(color, duration, times), halfDuration(duration/2) {};
    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);
private:
    const uint8_t lowerBrightness = 0;
    const uint8_t higherBrightness = 255;
    long halfDuration;
};

#endif