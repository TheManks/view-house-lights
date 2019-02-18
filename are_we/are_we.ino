#include "FastLED.h"
#include "CmdMessenger.h"
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];






//char buf[80];

/*int readline(int readch, char *buffer, int len) {
    static int pos = 0;
    int rpos;

    if (readch > 0) {
        switch (readch) {
            case '\r': // Ignore CR
                break;
            case '\n': // Return on new-line
                rpos = pos;
                pos = 0;  // Reset position index ready for next time
                return rpos;
            default:
                if (pos < len-1) {
                    buffer[pos++] = readch;
                    buffer[pos] = 0;
                }
        }
    }
    return 0;
}*/


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


    /*if(readline(Serial.read(), buf, 80) > 0) {
	Serial.print("You entered: >");
        Serial.print(buf);
        Serial.println("<");
        //i = atoi(buf);
        //FastLED.setBrightness(i);
        //FastLED.show();
    }
    FastLED.show();*/
}







/*  int data = 0;
    Serial.setTimeout(0);
    while (!Serial.available()) {} // wait
    while (Serial.available()) {
        data = Serial.parseInt();	
        FastLED.setBrightness((int)data);
	FastLED.show();
	Serial.print("Yo I got:");
	Serial.println(data);
	Serial.print("\n");
*/

/* 
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
}*/

