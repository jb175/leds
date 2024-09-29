#include <Arduino.h>
#include <FastLED.h>

#include <animations/soft/SoftGlow.h>
#include <animations/soft/SoftBreathing.h>
#include <animations/soft/SoftRainbowPulse.h>
#include <animations/soft/SoftBlinkingStars.h>
#include <animations/soft/SoftWaves.h>

#include <transitions/SlideTransition.h>
#include <transitions/ColorFadeTransition.h>
#include <transitions/NoTransition.h>
#include <ColorDefinition.h>

#define NUM_LEDS 60
#define DATA_PIN 2
#define TRANSITION_DURATION 5000 // Duration of the transition in milliseconds

CRGB leds[NUM_LEDS];
SoftAnimation* currentAnimation;
SoftAnimation* previousAnimation;
Transition* transition;
unsigned long lastIntervalChange = 0;
unsigned long transitionStartTime = 0;
CRGB lastColor;
CRGB currentColor;

const std::vector<CRGB> colors = {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, CRGB::Purple, CRGB::Cyan, CRGB::Orange};

void createNewTransition();
void createNewAnimation();
CRGB generateNewColor(const std::map<CRGB, std::vector<CRGB>>& colorMapping);
CRGB generateNewColor(const std::vector<CRGB>& colorMapping);

void setup() {
    CFastLED::addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
    randomSeed(analogRead(0) + millis());
    createNewAnimation();
    Serial.begin(115200);
}

void loop() {
    unsigned long timeElapsed = millis();

    //transition
    if (transition != nullptr) {
        unsigned long transitionElapsed = timeElapsed - transitionStartTime;

        if (transitionElapsed >= transition->getDuration()) {
            //close transition
            delete transition;
            transition = nullptr;
            lastIntervalChange = timeElapsed;
        } else {
            std::vector<CRGB> ledStates = transition->generateLEDs(NUM_LEDS, transitionElapsed);

            for (int i = 0; i < NUM_LEDS; i++) {
                leds[i] = ledStates[i];
            }

            FastLED.show();
            return;
        }
    }

    //animation
    unsigned long intervalElapsed = timeElapsed - lastIntervalChange;
    if (currentAnimation->getIsFinished(intervalElapsed)) {
        //finish animation
        createNewTransition();
        lastIntervalChange = timeElapsed;
    } else if (currentAnimation != nullptr) {
        std::vector<CRGB> ledStates = currentAnimation->generateLEDs(NUM_LEDS, intervalElapsed);

        for (int i = 0; i < NUM_LEDS; i++) {
            leds[i] = ledStates[i];
        }

        FastLED.show();
    } else {
        createNewAnimation();
    }
}

void createNewTransition() {
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
        transition = new SlideTransition(previousAnimation, currentAnimation, TRANSITION_DURATION, random(2));
        break;
    case 2:
        transition = new ColorFadeTransition(previousAnimation, currentAnimation, TRANSITION_DURATION);
        break;
    default:
        break;
    }
    transitionStartTime = millis();
}

void createNewAnimation() {
    if (previousAnimation != nullptr) {
        delete previousAnimation;
    }
    previousAnimation = currentAnimation;
    CRGB FinalColor;
    switch (random(0, 5))
    {
    case 0:
        currentColor = generateNewColor(basicColorMapping);
        currentAnimation = new SoftGlow(currentColor, TRANSITION_DURATION, random(2, 4));
        break;
    case 1:
        currentColor = generateNewColor(basicColorMapping);
        currentAnimation = new SoftBreathing(currentColor, TRANSITION_DURATION, random(2, 4));
        break;
    case 2:
        currentAnimation = new SoftRainbowPulse(TRANSITION_DURATION, random(1, 3));
        break;
    case 3:
        currentColor = generateNewColor(basicColorMapping);
        currentAnimation = new SoftBlinkingStars(currentColor, TRANSITION_DURATION, 1);
        break;
    case 4:
        currentColor = generateNewColor(basicColorMapping);
        currentAnimation = new SoftWaves(currentColor, TRANSITION_DURATION, random(2, 4), random(0, 2));
        break;
    default:
        break;
    }
}

CRGB generateNewColor(const std::map<CRGB, std::vector<CRGB>>& colorMapping) {
    if (colorMapping.find(currentColor) != colorMapping.end()) {
        return generateNewColor(colorMapping.at(currentColor));
    } else {
        auto it = colorMapping.begin();
        std::advance(it, random(0, colorMapping.size()));
        return it->first;
    }
}

CRGB generateNewColor(const std::vector<CRGB>& colorList) {
    if (colorList.size() <= 1) {
        return colorList[0];
    }
    CRGB newColor;
    do {
        newColor = colorList[random(0, colorList.size())];
    } while (newColor == currentColor);
    return newColor;
}