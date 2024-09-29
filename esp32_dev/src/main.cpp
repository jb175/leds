#include <Arduino.h>
#include <FastLED.h>
#include <animations/soft/SoftGlow.h>
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
void generateNewColor(const std::map<CRGB, std::vector<CRGB>>& colorMapping);
void generateNewColor(const std::vector<CRGB>& colorMapping);

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
    if (currentAnimation->getIsFinished()) {
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

    switch (random(2))
    {
    case 0:
    case 1:
        generateNewColor(basicColorMapping);
        currentAnimation = new SoftGlow(currentColor, TRANSITION_DURATION, random(3,5));
        break;
    default:
        break;
    }
}

void generateNewColor(const std::map<CRGB, std::vector<CRGB>>& colorMapping) {
    if (colorMapping.find(currentColor) != colorMapping.end()) {
        generateNewColor(colorMapping.at(currentColor));
    } else {
        auto it = colorMapping.begin();
        std::advance(it, random(0, colorMapping.size()));
        currentColor = it->first;
    }
}

void generateNewColor(const std::vector<CRGB>& colorList) {
    if (colorList.size() <= 1) {
        return;
    }
    CRGB newColor;
    do {
        newColor = colorList[random(0, colorList.size())];
    } while (newColor == currentColor);
    currentColor = newColor;
}