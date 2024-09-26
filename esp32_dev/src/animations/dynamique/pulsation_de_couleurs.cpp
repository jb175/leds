#include "leds.h"
#include "animations.h"

void pulsationDeCouleurs(unsigned long duration) {
    unsigned long startTime = millis();
    while (millis() - startTime < duration) {
        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < NUM_LEDS; j++) {
                leds[j] = CRGB(i, 0, 255 - i); // Passer du bleu au rouge
            }
            FastLED.show();
            delay(10);
        }
        for (int i = 255; i >= 0; i--) {
            for (int j = 0; j < NUM_LEDS; j++) {
                leds[j] = CRGB(i, 0, 255 - i); // Diminuer l'intensité
            }
            FastLED.show();
            delay(10);
        }
    }
}
