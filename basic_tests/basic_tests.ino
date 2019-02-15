#include "FastLED.h"
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];
void setup() { FastLED.addLeds<WS2812B, 9, GRB>(leds, NUM_LEDS); }
void loop() {
  for(int selected = 0; selected < NUM_LEDS; selected = selected + 1) {
      if (selected %2 == 0)
      {
        leds[selected] = CRGB::DarkBlue;
      }
      else
      {
        leds[selected] = CRGB::DarkRed;
      }
      FastLED.show();
      delay(1);
  }

  for(int selected = 0; selected < NUM_LEDS; selected = selected + 1) {
      // Turn our current led on to white, then show the leds
      leds[selected] = CRGB::Black;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(1);

      // Turn our current led back to black for the next loop around
  }
}

