#include "leds.h"
#include "animations.h"

void stroboscopeClassique(unsigned long duration) {
    unsigned long startTime = millis();
    while (millis() - startTime < duration) {
        fill_solid(leds, NUM_LEDS, CRGB(255, 255, 255)); // Lumière blanche
        FastLED.show();
        delay(100); // Temps allumé
        fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0)); // Éteindre
        FastLED.show();
        delay(100); // Temps éteint
    }
}
