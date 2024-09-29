#ifndef ANIMATIONTEST_H
#define ANIMATIONTEST_H

#include <animationLists/AnimationList.h>
#include <animations/Waves/Waves.h>
#include <transitions/No/NoTransition.h>

class AnimationTestList : public AnimationList {
public:
    AnimationTestList() : AnimationList(
        {
            {AnimationType::Waves, 100}
        },
        {
            {TransitionType::NoTransition, 100}
        }
    ) {};

    void createNewTransition() override;
    void createNewAnimation() override;
    const int animationBaseTime = 5000;
};

#endif