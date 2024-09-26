#include "leds.h"
#include "animations.h"

void changementDeCouleurs(unsigned long duration) {
    unsigned long startTime = millis();
    while (millis() - startTime < duration) {
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < NUM_LEDS; j++) {
                leds[j] = CHSV((i + j * (256 / NUM_LEDS)) % 256, 255, 128); // Dégradé de couleurs
            }
            FastLED.show();
            delay(20); // Délai pour contrôler la vitesse de changement
        }
    }
}
