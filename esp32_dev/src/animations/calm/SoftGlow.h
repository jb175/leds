#ifndef SOFTGLOW_H
#define SOFTGLOW_H

#include <FastLED.h>
#include <vector>
#include <animations/calm/CalmAnimation.h>

class SoftGlow : public CalmAnimation {
public:
    SoftGlow(CRGB color, unsigned long duration) : CalmAnimation(color, duration) {};
    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);
private:
    const uint8_t lowerBrightness = 0;
    const uint8_t higherBrightness = 255;
    long halfDuration = this->getDuration()/2;
};

#endif