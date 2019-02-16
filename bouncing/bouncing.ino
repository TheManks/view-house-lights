#include "FastLED.h"

#define NUM_LEDS 300
#define NUM_COLORS 150
// Length of bouncing bar (in # of LEDs, must be > NUM_LEDS)
#define TRAIN_LENGTH 5
// Length of delay between updates in ms
#define SPEED 1
// If true, LEDs turn off instead of on
#define REVERSED false
// If true, changes to random color on bounce
#define CHANGE_COLOR true

CRGB leds[NUM_LEDS];
CRGB colors[NUM_COLORS] = {CRGB::AliceBlue,
                           CRGB::Amethyst,
                           CRGB::AntiqueWhite,
                           CRGB::Aqua,
                           CRGB::Aquamarine,
                           CRGB::Azure,
                           CRGB::Beige,
                           CRGB::Bisque,
                           CRGB::BlanchedAlmond,
                           CRGB::Blue,
                           CRGB::BlueViolet,
                           CRGB::Brown,
                           CRGB::BurlyWood,
                           CRGB::CadetBlue,
                           CRGB::Chartreuse,
                           CRGB::Chocolate,
                           CRGB::Coral,
                           CRGB::CornflowerBlue,
                           CRGB::Cornsilk,
                           CRGB::Crimson,
                           CRGB::Cyan,
                           CRGB::DarkBlue,
                           CRGB::DarkCyan,
                           CRGB::DarkGoldenrod,
                           CRGB::DarkGray,
                           CRGB::DarkGrey,
                           CRGB::DarkGreen,
                           CRGB::DarkKhaki,
                           CRGB::DarkMagenta,
                           CRGB::DarkOliveGreen,
                           CRGB::DarkOrange,
                           CRGB::DarkOrchid,
                           CRGB::DarkRed,
                           CRGB::DarkSalmon,
                           CRGB::DarkSeaGreen,
                           CRGB::DarkSlateBlue,
                           CRGB::DarkSlateGray,
                           CRGB::DarkSlateGrey,
                           CRGB::DarkTurquoise,
                           CRGB::DarkViolet,
                           CRGB::DeepPink,
                           CRGB::DeepSkyBlue,
                           CRGB::DimGray,
                           CRGB::DimGrey,
                           CRGB::DodgerBlue,
                           CRGB::FireBrick,
                           CRGB::FloralWhite,
                           CRGB::ForestGreen,
                           CRGB::Fuchsia,
                           CRGB::Gainsboro,
                           CRGB::GhostWhite,
                           CRGB::Gold,
                           CRGB::Goldenrod,
                           CRGB::Gray,
                           CRGB::Grey,
                           CRGB::Green,
                           CRGB::GreenYellow,
                           CRGB::Honeydew,
                           CRGB::HotPink,
                           CRGB::IndianRed,
                           CRGB::Indigo,
                           CRGB::Ivory,
                           CRGB::Khaki,
                           CRGB::Lavender,
                           CRGB::LavenderBlush,
                           CRGB::LawnGreen,
                           CRGB::LemonChiffon,
                           CRGB::LightBlue,
                           CRGB::LightCoral,
                           CRGB::LightCyan,
                           CRGB::LightGoldenrodYellow,
                           CRGB::LightGreen,
                           CRGB::LightGrey,
                           CRGB::LightPink,
                           CRGB::LightSalmon,
                           CRGB::LightSeaGreen,
                           CRGB::LightSkyBlue,
                           CRGB::LightSlateGray,
                           CRGB::LightSlateGrey,
                           CRGB::LightSteelBlue,
                           CRGB::LightYellow,
                           CRGB::Lime,
                           CRGB::LimeGreen,
                           CRGB::Linen,
                           CRGB::Magenta,
                           CRGB::Maroon,
                           CRGB::MediumAquamarine,
                           CRGB::MediumBlue,
                           CRGB::MediumOrchid,
                           CRGB::MediumPurple,
                           CRGB::MediumSeaGreen,
                           CRGB::MediumSlateBlue,
                           CRGB::MediumSpringGreen,
                           CRGB::MediumTurquoise,
                           CRGB::MediumVioletRed,
                           CRGB::MidnightBlue,
                           CRGB::MintCream,
                           CRGB::MistyRose,
                           CRGB::Moccasin,
                           CRGB::NavajoWhite,
                           CRGB::Navy,
                           CRGB::OldLace,
                           CRGB::Olive,
                           CRGB::OliveDrab,
                           CRGB::Orange,
                           CRGB::OrangeRed,
                           CRGB::Orchid,
                           CRGB::PaleGoldenrod,
                           CRGB::PaleGreen,
                           CRGB::PaleTurquoise,
                           CRGB::PaleVioletRed,
                           CRGB::PapayaWhip,
                           CRGB::PeachPuff,
                           CRGB::Peru,
                           CRGB::Pink,
                           CRGB::Plaid,
                           CRGB::Plum,
                           CRGB::PowderBlue,
                           CRGB::Purple,
                           CRGB::Red,
                           CRGB::RosyBrown,
                           CRGB::RoyalBlue,
                           CRGB::SaddleBrown,
                           CRGB::Salmon,
                           CRGB::SandyBrown,
                           CRGB::SeaGreen,
                           CRGB::Seashell,
                           CRGB::Sienna,
                           CRGB::Silver,
                           CRGB::SkyBlue,
                           CRGB::SlateBlue,
                           CRGB::SlateGray,
                           CRGB::SlateGrey,
                           CRGB::Snow,
                           CRGB::SpringGreen,
                           CRGB::SteelBlue,
                           CRGB::Tan,
                           CRGB::Teal,
                           CRGB::Thistle,
                           CRGB::Tomato,
                           CRGB::Turquoise,
                           CRGB::Violet,
                           CRGB::Wheat,
                           CRGB::White,
                           CRGB::WhiteSmoke,
                           CRGB::Yellow,
                           CRGB::YellowGreen,
                           CRGB::FairyLight,
                           CRGB::FairyLightNCC};
CRGB selectedColor;

CRGB pickColor() {
    int ind = random(NUM_COLORS);
    return colors[ind];
}

void setup() {
    FastLED.addLeds<WS2812B, 9, GRB>(leds, NUM_LEDS);
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = !REVERSED ? CRGB::Black : selectedColor;
    }
    selectedColor = CRGB::White;
}
void loop() {
    for (int i = 0; i <= NUM_LEDS - TRAIN_LENGTH; i++) {
        for (int j = 0; j < i; j++) {
            leds[j] = !REVERSED ? CRGB::Black : selectedColor;
        }
        for (int j = 0; j < TRAIN_LENGTH; j++) {
            leds[i + j] = !REVERSED ? selectedColor : CRGB::Black;
        }
        delay(SPEED);
        FastLED.show();
    }

    if (CHANGE_COLOR) selectedColor = pickColor();

    for (int i = NUM_LEDS; i >= TRAIN_LENGTH; i--) {
        for (int j = NUM_LEDS; j > i; j--) {
            leds[j] = !REVERSED ? CRGB::Black : selectedColor;
        }
        for (int j = 0; j < TRAIN_LENGTH; j++) {
            leds[i - j] = !REVERSED ? selectedColor : CRGB::Black;
        }
        delay(SPEED);
        FastLED.show();
    }

    if (CHANGE_COLOR) selectedColor = pickColor();
}