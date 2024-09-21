//basic color cycle
#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN     18   // Pin where LED strip is connected
#define NUM_LEDS    60   // Number of LEDs in your strip
#define BRIGHTNESS  128  // Brightness level
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // Simple color cycle effect
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;  // Set all LEDs to blue
  }
  FastLED.show();
  delay(500);

  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;  // Set all LEDs to red
  }
  FastLED.show();
  delay(500);
}