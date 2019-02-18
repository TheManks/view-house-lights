/*
    This program will not work unless the time is
    synchronized to some absolute time reference.
    The Arduino can only use time relative to the
    when the program was started otherwise.

    Sync time using setTime() from Time.h
*/

#include "FastLED.h"
#include "TimeLib.h"
#define NUM_LEDS 300
#define MINUTES_IN_DAY (24 * 60)

bool blink;

CRGB leds[NUM_LEDS];
void setup() {
    FastLED.addLeds<WS2812B, 9, GRB>(leds, NUM_LEDS);
    blink = false;
}
void loop() {
    float time = hour() * 60 + minute();
    int num = (time / MINUTES_IN_DAY) * NUM_LEDS;

    for (int i = 0; i < num; i++) {
        leds[i] = CRGB::White;

        if (blink && (i == num - 1)) {
            leds[i] = CRGB::Black;
        }
        FastLED.show();
    }

    blink = !blink;

    delay(1000);
}
