#include "leds.h"
#include "animations.h"

void effectDeFlash(unsigned long duration) {
    unsigned long startTime = millis();
    while (millis() - startTime < duration) {
        fill_solid(leds, NUM_LEDS, CRGB(255, 0, 0)); // Flash rouge
        FastLED.show();
        delay(100);
        fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0)); // Éteindre
        FastLED.show();
        delay(100);
    }
}
