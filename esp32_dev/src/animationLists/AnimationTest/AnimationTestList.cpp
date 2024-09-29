#include "AnimationTestList.h"
#include <ColorDefinition.h>

void AnimationTestList::createNewTransition() {
    createNewAnimation();
    setTransition(new NoTransition());
    setTransitionStartTime(millis());
}

void AnimationTestList::createNewAnimation() {
    setPreviousAnimation(getCurrentAnimation());
    setCurrentColor(generateNewColor(basicColorMapping));
    setCurrentAnimation(new Waves(getCurrentColor(), animationBaseTime, random(2, 4), random(0, 2)));
}