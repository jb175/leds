#ifndef SOFTANIMATIONLIST_H
#define SOFTANIMATIONLIST_H

#include <Arduino.h>
#include <FastLED.h>
#include "AnimationList.h"
#include <animations/soft/SoftGlow.h>
#include <animations/soft/SoftBreathing.h>
#include <animations/soft/SoftRainbowPulse.h>
#include <animations/soft/SoftBlinkingStars.h>
#include <animations/soft/SoftWaves.h>
#include <transitions/SlideTransition.h>
#include <transitions/ColorFadeTransition.h>
#include <transitions/NoTransition.h>
#include <ColorDefinition.h>

class SoftAnimationList : public AnimationList {
public:
    void createNewTransition() override;
    void createNewAnimation() override;
    void runAnimationList(CRGB* leds, int numLeds, unsigned long timeElapsed) override;
    const int animationBaseTime = 5000;
    
private:
    Animation* currentAnimation = nullptr;
    Animation* previousAnimation = nullptr;
    Transition* transition = nullptr;
    unsigned long lastIntervalChange = 0;
    unsigned long transitionStartTime = 0;
    CRGB lastColor;
    CRGB currentColor;
    const std::vector<CRGB> colors = {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, CRGB::Purple, CRGB::Cyan, CRGB::Orange};

    CRGB generateNewColor(const std::map<CRGB, std::vector<CRGB>>& colorMapping);
    CRGB generateNewColor(const std::vector<CRGB>& colorList);
};

#endif