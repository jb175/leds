#include "SoftAnimationList.h"

void SoftAnimationList::createNewTransition() {
    createNewAnimation();

    if (transition != nullptr) {
        delete transition;
    }
    switch (random(0, 3))
    {
    case 0:
        transition = new NoTransition();
        break;
    case 1:
        transition = new SlideTransition(previousAnimation, currentAnimation, animationBaseTime, random(2));
        break;
    case 2:
        transition = new ColorFadeTransition(previousAnimation, currentAnimation, animationBaseTime);
        break;
    default:
        break;
    }
    transitionStartTime = millis();
}

void SoftAnimationList::createNewAnimation() {
    if (previousAnimation != nullptr) {
        delete previousAnimation;
    }
    previousAnimation = currentAnimation;
    CRGB FinalColor;
    switch (random(0, 5))
    {
    case 0:
        currentColor = generateNewColor(basicColorMapping);
        currentAnimation = new SoftGlow(currentColor, animationBaseTime, random(2, 4));
        break;
    case 1:
        currentColor = generateNewColor(basicColorMapping);
        currentAnimation = new SoftBreathing(currentColor, animationBaseTime, random(2, 4));
        break;
    case 2:
        currentAnimation = new SoftRainbowPulse(animationBaseTime, random(1, 3));
        break;
    case 3:
        currentColor = generateNewColor(basicColorMapping);
        currentAnimation = new SoftBlinkingStars(currentColor, animationBaseTime, 1);
        break;
    case 4:
        currentColor = generateNewColor(basicColorMapping);
        currentAnimation = new SoftWaves(currentColor, animationBaseTime, random(2, 4), random(0, 2));
        break;
    default:
        break;
    }
}

CRGB SoftAnimationList::generateNewColor(const std::map<CRGB, std::vector<CRGB>>& colorMapping) {
    if (colorMapping.find(currentColor) != colorMapping.end()) {
        return generateNewColor(colorMapping.at(currentColor));
    } else {
        auto it = colorMapping.begin();
        std::advance(it, random(0, colorMapping.size()));
        return it->first;
    }
}

CRGB SoftAnimationList::generateNewColor(const std::vector<CRGB>& colorList) {
    if (colorList.size() <= 1) {
        return colorList[0];
    }
    CRGB newColor;
    do {
        newColor = colorList[random(0, colorList.size())];
    } while (newColor == currentColor);
    return newColor;
}

void SoftAnimationList::runAnimationList(CRGB* leds, int numLeds, unsigned long timeElapsed) {
    // Transition
    if (transition != nullptr) {
        unsigned long transitionElapsed = timeElapsed - transitionStartTime;

        if (transitionElapsed >= transition->getDuration()) {
            // Close transition
            delete transition;
            transition = nullptr;
            lastIntervalChange = timeElapsed;
        } else {
            std::vector<CRGB> ledStates = transition->generateLEDs(numLeds, transitionElapsed);

            for (int i = 0; i < numLeds; i++) {
                leds[i] = ledStates[i];
            }

            FastLED.show();
            return;
        }
    }

    // Animation
    unsigned long intervalElapsed = timeElapsed - lastIntervalChange;
    if (currentAnimation->getIsFinished(intervalElapsed)) {
        // Finish animation
        createNewTransition();
        lastIntervalChange = timeElapsed;
    } else if (currentAnimation != nullptr) {
        std::vector<CRGB> ledStates = currentAnimation->generateLEDs(numLeds, intervalElapsed);

        for (int i = 0; i < numLeds; i++) {
            leds[i] = ledStates[i];
        }

        FastLED.show();
    } else {
        createNewAnimation();
    }
}