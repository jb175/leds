#include <Arduino.h>
#include <FastLED.h>
#include <animationLists/AnimationList.h>
#include <animationLists/Soft/SoftAnimationList.h>
#include <animationLists/AnimationTest/AnimationTestList.h>
#include <animationLists/TransitionTest/TransitionTestList.h>

#define NUM_LEDS 60
#define DATA_PIN 13

CRGB leds[NUM_LEDS];
AnimationList* animationList = new TransitionTestList();

void setup() {
    CFastLED::addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
    randomSeed(analogRead(0) + millis());
    animationList->createNewAnimation();
    Serial.begin(115200);
}

void loop() {
    unsigned long timeElapsed = millis();
    animationList->runAnimationList(leds, NUM_LEDS, timeElapsed);
}