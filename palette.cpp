#include <FastLED.h>
#include "palette.h"

FASTLED_USING_NAMESPACE

extern const TProgmemRGBPalette16 irPalette FL_PROGMEM =
{ CRGB::DarkRed,
  CRGB::DarkGreen,
  CRGB::DarkBlue,
  CRGB::White,

  CRGB::Red,
  CRGB::Green,
  CRGB::Blue,

  CRGB::DarkOrange,
  CRGB::Turquoise,
  CRGB::Navy,

  CRGB::Orange,
  CRGB::Teal,
  CRGB::Purple,

  CRGB::Yellow,
  CRGB::RoyalBlue,
  CRGB::Magenta,
};


CRGB mapCodeToColor(uint8_t code) {
  uint8_t index = 255;
  switch (code) {
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10: index = code - 4; break;
    case 12:
    case 13:
    case 14: index =  code - 5; break;
    case 16:
    case 17:
    case 18: index =  code - 6; break;
    case 20:
    case 21:
    case 22: index =  code - 7; break;
    default: index =  255;
  }
  
  if (index == 255) {
    return CRGB::Black;
  }

  return ColorFromPalette(irPalette, index << 4, 255, NOBLEND);
}
