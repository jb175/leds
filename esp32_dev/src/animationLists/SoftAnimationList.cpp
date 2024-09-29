#include "SoftAnimationList.h"
#include <ColorDefinition.h>

void SoftAnimationList::createNewTransition() {
    createNewAnimation();

    TransitionType transitionType = selectRandomWithProbability(getTransitionProbabilities());
    switch (transitionType)
    {
        case TransitionType::NoTransition:
            setTransition(new NoTransition());
            break;
        case TransitionType::SlideTransition:
            setTransition(new SlideTransition(getPreviousAnimation(), getCurrentAnimation(), animationBaseTime, random(2)));
            break;
        case TransitionType::ColorFadeTransition:
            setTransition(new ColorFadeTransition(getPreviousAnimation(), getCurrentAnimation(), animationBaseTime));
            break;
        default:
            break;
    }
    setTransitionStartTime(millis());
}

void SoftAnimationList::createNewAnimation() {
    setPreviousAnimation(getCurrentAnimation());

    AnimationType animationType = selectRandomWithProbability(getAnimationProbabilities());
    setCurrentColor(generateNewColor(basicColorMapping));
    switch (animationType)
    {
        case AnimationType::SoftGlow:
            setCurrentAnimation(new SoftGlow(getCurrentColor(), animationBaseTime, random(2, 4)));
            break;
        case AnimationType::SoftBreathing:
            setCurrentAnimation(new SoftBreathing(getCurrentColor(), animationBaseTime, random(2, 4)));
            break;
        case AnimationType::SoftRainbowPulse:
            setCurrentAnimation(new SoftRainbowPulse(animationBaseTime, random(1, 3)));
            break;
        case AnimationType::SoftBlinkingStars:
            setCurrentAnimation(new SoftBlinkingStars(getCurrentColor(), animationBaseTime, 1));
            break;
        case AnimationType::SoftWaves:
            setCurrentAnimation(new SoftWaves(getCurrentColor(), animationBaseTime, random(2, 4), random(0, 2)));
            break;
        default:
            break;
    }
}