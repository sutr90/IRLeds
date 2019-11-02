#include "config.h"
#include "animate.h"
#include <FastLED.h>

static uint8_t colorIndex = 0;

void animate(uint8_t code, LedArray &leds){
	if(code == 11){
		EVERY_N_SECONDS( 1 ) { colorIndex++; }
	} 
	
	if(code == 15){
		EVERY_N_MILLISECONDS( 600 ) { colorIndex++; }
	}
	
	if(code == 19){
		EVERY_N_MILLISECONDS( 200 ) { colorIndex++; }
	}
	
	if(code == 23){
		EVERY_N_MILLISECONDS( 50 ) { colorIndex++; }
	}
	
	leds.fill_solid(ColorFromPalette(RainbowColors_p, colorIndex, 255, LINEARBLEND));
}