#ifndef LEDS_H  // Protection contre les inclusions multiples
#define LEDS_H

#include <FastLED.h>

#define NUM_LEDS 60
#define DATA_PIN 2

extern CRGB leds[NUM_LEDS]; // Déclaration de la variable led

#endif // LEDS_H
