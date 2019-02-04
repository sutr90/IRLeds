#include <FastLED.h>
#include "command.h"
#include "palette.h"

FASTLED_USING_NAMESPACE

#define MAX_BRIGHTNESS 16

static uint8_t brightness = 8;
static uint8_t lastColorCode = 7; // white

void color(uint8_t code, LedArray &leds) {
	lastColorCode = code;
  leds.fill_solid(mapCodeToColor(code));
}

void turnOff(LedArray &leds) {
  leds.fill_solid(CRGB::Black);
}

uint8_t mapBrightness(uint8_t level) {
  switch (level) {
    case 0: return 0;
    case 1: return 16;
    case 2: return 32;
    case 3: return 48;
    case 4: return 64;
    case 5: return 80;
    case 6: return 96;
    case 7: return 112;
    case 8: return 128;
	case 9: return 144;
    case 10: return 160;
    case 11: return 176;
    case 12: return 192;
    case 13: return 208;
    case 14: return 224;
    case 15: return 240;
    case 16: return 255;
  }
}

void changeBrightness(uint8_t code){
  if (code == 	0) {
    brightness++;
  }

  if (code == 1) {
    brightness--;
  }

  brightness = brightness == MAX_BRIGHTNESS + 1 ? MAX_BRIGHTNESS : brightness;
  brightness = brightness == 255 ? 0 : brightness;

  FastLED.setBrightness(mapBrightness(brightness));
}

void controlSwitch(uint8_t code, LedArray &leds){
	Serial.print("controlSwitch");
	Serial.println(code);
	Serial.print("lastColorCode");
	Serial.println(lastColorCode);
	
	if(code == 2) {
		turnOff(leds);
	}
	
	if(code == 3){
		color(lastColorCode, leds);
	}
}

void controls(uint8_t code, LedArray &leds) {
	
	switch(code){
		case 0:
		case 1: changeBrightness(code); return;
		case 2:
		case 3: controlSwitch(code, leds); return;
	}
	
}


void flash(uint8_t code) {
  /* todo */
}
void strobe(uint8_t code) {
  /* todo */
}
void fade(uint8_t code) {
  /* todo */
}
void smooth(uint8_t code) {
  /* todo */
}

void processCommand(uint8_t code, LedArray &leds) {
	Serial.print("command");
	Serial.println(code);
	
  switch (code) {
    case 0:
    case 1:
    case 2:
    case 3: controls(code, leds); return;
    case 11: flash(code); return;
    case 15: strobe(code); return;
    case 19: fade(code); return;
    case 23: smooth(code); return;
    default: color(code, leds);
  }
}
