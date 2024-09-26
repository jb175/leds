#include "leds.h"
#include "animations.h"

void etoilesClignotantes(unsigned long duration) {
    unsigned long startTime = millis();
    while (millis() - startTime < duration) {
        for (int i = 0; i < NUM_LEDS; i++) {
            leds[i] = CRGB(0, 0, 0); // Éteindre toutes les LEDs
        }
        for (int i = 0; i < 10; i++) {
            int index = random(0, NUM_LEDS);
            leds[index] = CRGB(255, 255, 255); // Allumer une LED aléatoire
            FastLED.show();
            delay(random(100, 300)); // Clignoter de manière aléatoire
            leds[index] = CRGB(0, 0, 0); // Éteindre la LED
        }
    }
}
