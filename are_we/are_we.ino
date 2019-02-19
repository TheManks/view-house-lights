#include "FastLED.h"
#include "CmdMessenger.h"
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];


CmdMessenger cmdMessenger = CmdMessenger(Serial);
enum {
    setLed,
};
void attachCommandCallbacks() {
    cmdMessenger.attach(setLed, OnSetLed);
}

void OnSetLed() {
    int ledState = cmdMessenger.readBinArg<int>();
    FastLED.setBrightness(ledState);
    FastLED.show();
}

void setup() {
    FastLED.addLeds<WS2812B, 9, GRB>(leds, NUM_LEDS);
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::White;
    }
    Serial.begin(115200);
    cmdMessenger.printLfCr();
    attachCommandCallbacks();
}
void loop() {
    cmdMessenger.feedinSerialData();


}



