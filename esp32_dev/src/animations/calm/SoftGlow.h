#ifndef SOFTGLOW_H
#define SOFTGLOW_H

#include <FastLED.h>
#include <vector>

class SoftGlow {
public:
    SoftGlow(CRGB color, unsigned long duration);
    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);

private:
    CRGB color;
    unsigned long duration;
};

#endif // SOFTGLOW_H