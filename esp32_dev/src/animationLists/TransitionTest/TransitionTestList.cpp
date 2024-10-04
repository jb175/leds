#include "TransitionTestList.h"
#include <ColorDefinition.h>

void TransitionTestList::createNewTransition() {
    createNewAnimation();
    setTransition(new SlideTransition(getPreviousAnimation(), getCurrentAnimation(), animationBaseTime));
    setTransitionStartTime(millis());
}

void TransitionTestList::createNewAnimation() {
    setPreviousAnimation(getCurrentAnimation());
    setCurrentColor(generateNewColor(basicColorMapping));
    setCurrentAnimation(new BasicColor(getCurrentColor(), 0, 1));
}