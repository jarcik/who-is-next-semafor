//library for led strip
#include <FastLED.h>
//how many leds to light
#define NUM_LEDS 30
//data on pin
#define DATA_PIN 3
#define CLOCK_PIN 13

//led array
CRGB leds[NUM_LEDS];
//what colors in which order
uint32_t colors[] = {CRGB::Green, CRGB::Yellow, CRGB::Blue};
//how much to wait (in milis)
int wait = 3 * 10000;

//setup
void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(2000);
  //led strip init
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  //clear to be safe
  clearLed();
}

//main
void loop() {
  // copied from arduino reference because the for loop for colors didnt work well for me :(
  //this for loop works correctly with an array of any type or size - Note that sizeof returns the total number of bytes. So for arrays of larger variable types such as ints, the for loop would look something like this.
  
  
  //loop throught the array of colors
  for (byte i = 0; i < (sizeof(colors) / sizeof(colors[0])); i++) {
    //show color
    whoIsNext(colors[i]);
  }
}

//show colors
void whoIsNext(uint32_t color) {
  //fill by defined color
  fill_solid(leds, NUM_LEDS, color);
  //show
  FastLED.show();
  //wait for defined time
  delay(wait);
  //clear to be safe
  clearLed();
  //delay to be safe
  delay(1000);
}

//clear led to be safe
void clearLed() {
  //clear to be safe
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.clear();
  //show clear
  FastLED.show();  
}

