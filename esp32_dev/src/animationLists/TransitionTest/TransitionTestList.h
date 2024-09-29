#ifndef TRANSITIONTEST_H
#define TRANSITIONTEST_H

#include <animationLists/AnimationList.h>
#include <animations/BasicColor/BasicColor.h>
#include <transitions/No/NoTransition.h>

class TransitionTestList : public AnimationList {
public:
    TransitionTestList() : AnimationList(
        {
            {AnimationType::BasicColor, 100}
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