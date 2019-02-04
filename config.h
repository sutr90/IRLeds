#pragma once
#include <FastLED.h>

FASTLED_USING_NAMESPACE

#define DATA_PIN    4
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    60

typedef CRGBArray<NUM_LEDS> LedArray;

#define FRAMES_PER_SECOND  60