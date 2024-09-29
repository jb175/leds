#ifndef SOFTRAINBOWPULSE_H
#define SOFTRAINBOWPULSE_H

#include <FastLED.h>
#include <animations/Animation.h>

class RainbowPulse : public Animation {
public:
    RainbowPulse(unsigned long duration, unsigned int times) 
        : Animation(CRGB::Black, duration, times) {}

    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);
};

#endif
