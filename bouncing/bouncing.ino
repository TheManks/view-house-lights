#include "FastLED.h"
#define NUM_LEDS 300
#define TRAIN_LENGTH 5 // Length of bouncing bar (in # of LEDs, must be > NUM_LEDS)
#define SPEED 1        // Length of delay between updates in ms
#define REVERSED false // If true, LEDs turn off instead of on

CRGB leds[NUM_LEDS];

void setup()
{
    FastLED.addLeds<WS2812B, 9, GRB>(leds, NUM_LEDS);
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = !REVERSED ? CRGB::Black : CRGB::White;
    }
}
void loop()
{
    for (int i = 0; i <= NUM_LEDS - TRAIN_LENGTH; i++)
    {
        for (int j = 0; j < i; j++)
        {
            leds[j] = !REVERSED ? CRGB::Black : CRGB::White;
        }
        for (int j = 0; j < TRAIN_LENGTH; j++)
        {
            leds[i + j] = !REVERSED ? CRGB::White : CRGB::Black;
        }
        delay(SPEED);
        FastLED.show();
    }

    for (int i = NUM_LEDS; i >= TRAIN_LENGTH; i--)
    {
        for (int j = NUM_LEDS; j > i; j--)
        {
            leds[j] = !REVERSED ? CRGB::Black : CRGB::White;
        }
        for (int j = 0; j < TRAIN_LENGTH; j++)
        {
            leds[i - j] = !REVERSED ? CRGB::White : CRGB::Black;
        }
        delay(SPEED);
        FastLED.show();
    }
}
