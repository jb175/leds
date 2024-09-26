#include <Arduino.h>
#include <FastLED.h>
#include "leds.h"
#include "animations.h"

void lueurDouce(unsigned long duration) {
    unsigned long startTime = millis();
    while (millis() - startTime < duration) {
        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < NUM_LEDS; j++) {
                leds[j] = CRGB(i, i, i); // Lueur blanche
            }
            FastLED.show();
            delay(10);
        }
        for (int i = 255; i >= 0; i--) {
            for (int j = 0; j < NUM_LEDS; j++) {
                leds[j] = CRGB(i, i, i); // Diminution de la lueur
            }
            FastLED.show();
            delay(10);
        }
    }
}
