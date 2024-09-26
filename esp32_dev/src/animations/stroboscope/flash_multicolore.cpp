#include "leds.h"
#include "animations.h"

void flashMulticolore(unsigned long duration) {
    unsigned long startTime = millis();
    while (millis() - startTime < duration) {
        fill_solid(leds, NUM_LEDS, CRGB(random(255), random(255), random(255))); // Couleur aléatoire
        FastLED.show();
        delay(50); // Flash rapide
        fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0)); // Éteindre
        FastLED.show();
        delay(50);
    }
}
