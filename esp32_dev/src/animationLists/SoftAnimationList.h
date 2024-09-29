#ifndef SOFTANIMATIONLIST_H
#define SOFTANIMATIONLIST_H

#include "AnimationList.h"
#include <animations/soft/SoftGlow.h>
#include <animations/soft/SoftBreathing.h>
#include <animations/soft/SoftRainbowPulse.h>
#include <animations/soft/SoftBlinkingStars.h>
#include <animations/soft/SoftWaves.h>
#include <transitions/SlideTransition.h>
#include <transitions/ColorFadeTransition.h>
#include <transitions/NoTransition.h>

class SoftAnimationList : public AnimationList {
public:
    SoftAnimationList() : AnimationList(
        {
            {AnimationType::SoftGlow, 20},
            {AnimationType::SoftBreathing, 20},
            {AnimationType::SoftRainbowPulse, 20},
            {AnimationType::SoftBlinkingStars, 20},
            {AnimationType::SoftWaves, 20}
        },
        {
            {TransitionType::NoTransition, 40},
            {TransitionType::SlideTransition, 30},
            {TransitionType::ColorFadeTransition, 30}
        }
    ) {};

    void createNewTransition() override;
    void createNewAnimation() override;
    const int animationBaseTime = 5000;
};

#endif