#include "TransitionTestList.h"
#include <ColorDefinition.h>

void TransitionTestList::createNewTransition() {
    createNewAnimation();
    setTransition(new NoTransition());
    setTransitionStartTime(millis());
}

void TransitionTestList::createNewAnimation() {
    setPreviousAnimation(getCurrentAnimation());
    setCurrentColor(generateNewColor(basicColorMapping));
    setCurrentAnimation(new BasicColor(getCurrentColor(), animationBaseTime, 1));
}