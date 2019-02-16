#include "FastLED.h"
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<WS2812B, 9, GRB>(leds, NUM_LEDS);
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::White;
    }
}
void loop() {
    for (int i = 0; i <= 255; i++) {
        FastLED.setBrightness(i);
        FastLED.show();
    }

    FastLED.show();
    delay(500);

    for (int i = 255; i >= 0; i--) {
        FastLED.setBrightness(i);
        FastLED.show();
    }
    delay(500);
}
