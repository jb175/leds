#include <Arduino.h>
#include <FastLED.h>
#include <animations/calm/SoftGlow.h>
#include <transitions/SlideTransition.h>
#include <transitions/NoTransition.h>

#define NUM_LEDS 60
#define DATA_PIN 2
#define COLOR_INTERVAL 10000 // Time interval for each color in milliseconds
#define GLOW_INTERVAL 5000 // Time interval to transition from previous to new color in milliseconds
#define TRANSITION_DURATION 5000 // Duration of the transition in milliseconds

CRGB leds[NUM_LEDS];
CalmAnimation* currentAnimation;
CalmAnimation* previousAnimation;
Transition* transition;
unsigned long lastIntervalChange = 0;
unsigned long transitionStartTime = 0;
CRGB lastColor;
CRGB currentColor;

const std::vector<CRGB> colors = {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, CRGB::Purple, CRGB::Cyan, CRGB::Orange};

void createNewTransition();
void createNewAnimation();


void setup() {
    CFastLED::addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
    randomSeed(analogRead(0));
    createNewAnimation();
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
    if (intervalElapsed >= COLOR_INTERVAL) {
        //finish animation
        createNewAnimation();
        createNewTransition();
        lastIntervalChange = timeElapsed;
    } else if (currentAnimation != nullptr) {
        std::vector<CRGB> ledStates = currentAnimation->generateLEDs(NUM_LEDS, intervalElapsed);

        for (int i = 0; i < NUM_LEDS; i++) {
            leds[i] = ledStates[i];
        }

        FastLED.show();
    }
}

void createNewTransition() {
    // Create a new transition
    if (transition != nullptr) {
        delete transition; // Delete the old transition object
    }
    switch (random(0, 2))
    {
    case 0:
        transition = new NoTransition();
        break;
    case 1:
        transition = new SlideTransition(previousAnimation, currentAnimation, TRANSITION_DURATION);
        break;
    default:
        break;
    }
    transitionStartTime = millis(); // Set the start time for the transition
}

void createNewAnimation() {
    // Update the previous animation
    if (previousAnimation != nullptr) {
        delete previousAnimation;
    }
    previousAnimation = currentAnimation;

    // Generate a new color
    CRGB newColor;
    do {
        newColor = colors[random(0, colors.size())];
    } while (newColor == currentColor);

    // Create a new SoftGlow with the new color
    currentAnimation = new SoftGlow(newColor, GLOW_INTERVAL);

    //update the current color
    currentColor = newColor; // Update the current color
}

