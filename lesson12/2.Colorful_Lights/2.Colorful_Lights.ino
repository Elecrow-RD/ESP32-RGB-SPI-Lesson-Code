#include <FastLED.h>
CRGB leds[4];                  //Used to store 4 RGB_LEDs, leds[0] is the first light
CRGB myRGBcolor(0, 0, 0);      //Initialize the PWM values of R, G, B, range 0-255
void setup() {
  FastLED.addLeds<WS2812, 19, GRB>(leds, 4); //RGB light pin 25, the number of lights is 4
  FastLED.setBrightness(100);                //RGB light brightness range 0-255
  while(!(digitalRead(18)==0));
}
void loop() {
  for (int i = 0; i <= 3; i++) {
    myRGBcolor.r = random(0, 256);           //The random brightness of the red light is 0-255
    myRGBcolor.g = random(0, 256);
    myRGBcolor.b = random(0, 256);
    leds[i] = myRGBcolor;
    FastLED.show();                          //Display
    delay(50);
//  }
//  for (int i = 0; i <= 3; i++) {
    leds[i] = CRGB::Black;                   //Display black, that is, turn off the light
    FastLED.show();
    delay(50);
  }
}
