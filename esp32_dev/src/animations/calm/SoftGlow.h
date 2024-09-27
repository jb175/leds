#ifndef SOFTGLOW_H
#define SOFTGLOW_H

#include "CalmAnimation.h"

class SoftGlow : public CalmAnimation {
public:
    SoftGlow(CRGB color = CRGB::White, unsigned long duration = 5000, float pulseShape = 2.0, bool startAtFullBrightness = false);
    ~SoftGlow() override = default;
    void generateLEDs(CRGB* leds, int numLeds, unsigned long timeElapsed) override;

private:
    CRGB color;
    unsigned long duration;
    float pulseShape;
    bool startAtFullBrightness;
};

#endif // SOFTGLOW_H