#ifndef TRANSITIONTEST_H
#define TRANSITIONTEST_H

#include <animationLists/AnimationList.h>
#include <animations/BasicColor/BasicColor.h>
#include <transitions/No/NoTransition.h>
#include <transitions/ColorFade/ColorFadeTransition.h>
#include <transitions/Slide/SlideTransition.h>

class TransitionTestList : public AnimationList {
public:
    TransitionTestList() : AnimationList(
        {
            {AnimationType::BasicColor, 100}
        },
        {
            {TransitionType::SlideTransition, 100}
        }
    ) {};

    void createNewTransition() override;
    void createNewAnimation() override;
    const int animationBaseTime = 1000;
};

#endif