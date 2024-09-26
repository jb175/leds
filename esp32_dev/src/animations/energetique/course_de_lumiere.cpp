#include "leds.h"
#include "animations.h"

void courseDeLumiere(unsigned long duration) {
    unsigned long startTime = millis();
    while (millis() - startTime < duration) {
        for (int i = 0; i < NUM_LEDS; i++) {
            leds[i] = CRGB(255, 255, 0); // Lumière jaune
            FastLED.show();
            delay(50);
            leds[i] = CRGB(0, 0, 0); // Éteindre la LED
        }
    }
}
