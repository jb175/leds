#ifndef SOFTBLINKINGSTARS_H
#define SOFTBLINKINGSTARS_H

#include <FastLED.h>
#include <animations/Animation.h>

class BlinkingStars : public Animation {
public:
    BlinkingStars(CRGB color, unsigned long duration, unsigned int times) 
        : Animation(color, duration, times) {}

    std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed);

private:
    CRGB dimStarColor(CRGB color, uint8_t brightness);
};

#endif
