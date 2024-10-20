#include <Arduino.h>
#include <FastLED.h>
#include <array>
#include <animationLists/AnimationList.h>
#include <animationLists/Soft/SoftAnimationList.h>
#include <animationLists/AnimationTest/AnimationTestList.h>
#include <animationLists/TransitionTest/TransitionTestList.h>

#define NUM_LEDS 60
#define DATA_PIN 13

std::vector<std::vector<CRGB>> leds;
AnimationList* animationList = new TransitionTestList();

void setup() {
    leds[0].emplace_back(60);
    CFastLED::addLeds<WS2812B, DATA_PIN, RGB>(leds[0].data(), NUM_LEDS);
    randomSeed(analogRead(0) + millis());
    animationList->createNewAnimation();
    Serial.begin(115200);
}

void loop() {
    unsigned long timeElapsed = millis();
    animationList->runAnimationList(leds[0].data(), NUM_LEDS, timeElapsed);
}