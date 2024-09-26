#include "leds.h"
#include "animations.h"

void vagueDeCouleurs(unsigned long duration) {
    unsigned long startTime = millis();
    while (millis() - startTime < duration) {
        for (int j = 0; j < NUM_LEDS; j++) {
            int hue = (j * 255 / NUM_LEDS) + millis() / 10; // Changement de teinte en fonction du temps
            leds[j] = CHSV(hue, 255, 255); // Couleurs en HSV
        }
        FastLED.show();
        delay(50);
    }
}
