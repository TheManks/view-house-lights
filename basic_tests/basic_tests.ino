#include "FastLED.h"
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];
void setup() { FastLED.addLeds<WS2812B, 9, GRB>(leds, NUM_LEDS); }
void loop() {
  for(int selected = 0; selected < NUM_LEDS; selected = selected + 1) {
      if (selected %2 == 0)
      {
        leds[selected] = CRGB::FairyLight;
      }
      else
      {
        leds[selected] = CRGB::FairyLightNCC;
      }
      FastLED.show();
      delay(1);
  }

  for(int selected = 0; selected < NUM_LEDS; selected = selected + 1) {
      leds[selected] = CRGB::Black;
      FastLED.show();
      delay(1);
  }
}

