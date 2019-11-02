#include <FastLED.h>
#include "config.h"
#include "command.h"
#include "animate.h"

FASTLED_USING_NAMESPACE
LedArray leds;

static uint8_t lastCommand = 7;
static bool animation = false;

void setup() {
  delay(3000); // 3 second delay for recovery

  Serial.begin(9600);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(128);
  processCommand(7, leds);
  FastLED.show();
}

void loop()
{
  if (Serial.available()) {
    uint8_t command = Serial.read();
    bool tmp = processCommand(command, leds);
	
	//Serial.println(command);
	if(command > 3){ // don't cancel the animation when changing brightness
		lastCommand = command;
		animation = tmp;
	}
  }
  
  if(animation) {
	  animate(lastCommand, leds);
  }
  
  FastLED.show(); 
  FastLED.delay(1000/FRAMES_PER_SECOND); 
}
