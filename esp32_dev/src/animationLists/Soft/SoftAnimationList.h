#ifndef SOFTANIMATIONLIST_H
#define SOFTANIMATIONLIST_H

#include <animationLists/AnimationList.h>
#include <animations/Glow/Glow.h>
#include <animations/Breathing/Breathing.h>
#include <animations/RainbowPulse/RainbowPulse.h>
#include <animations/BlinkingStars/BlinkingStars.h>
#include <animations/Waves/Waves.h>
#include <transitions/ColorFade/ColorFadeTransition.h>
#include <transitions/No/NoTransition.h>
#include <transitions/Slide/SlideTransition.h>

class SoftAnimationList : public AnimationList {
public:
    SoftAnimationList() : AnimationList(
        {
            {AnimationType::Breathing, 50},
            {AnimationType::RainbowPulse, 15},
            {AnimationType::BlinkingStars, 5},
            {AnimationType::Waves, 30}
        },
        {
            {TransitionType::NoTransition, 40},
            {TransitionType::SlideTransition, 40},
            {TransitionType::ColorFadeTransition, 20}
        }
    ) {};

    void createNewTransition() override;
    void createNewAnimation() override;
    const int animationBaseTime = 5000;
};

#endif