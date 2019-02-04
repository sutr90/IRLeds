#include <FastLED.h>
#include "config.h"
#include "command.h"

FASTLED_USING_NAMESPACE
LedArray leds;

void setup() {
  delay(3000); // 3 second delay for recovery

  Serial.begin(9600);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( UncorrectedColor );
  FastLED.setBrightness(128);
  processCommand(7, leds);
  FastLED.show();
}

void loop()
{
  if (Serial.available()) {
    byte x = Serial.read();
    processCommand(x, leds);
  }
  
  FastLED.show(); 
  FastLED.delay(1000/FRAMES_PER_SECOND); 
}
