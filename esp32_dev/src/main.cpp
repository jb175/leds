#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN     18
#define NUM_LEDS    60
#define BRIGHTNESS  128
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Red;  // Set all LEDs to red
    }
    FastLED.show();
    delay(500);

    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Blue;  // Set all LEDs to blue
    }
    FastLED.show();
    delay(500);
}
