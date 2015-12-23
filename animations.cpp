#include "animations.h"

NeoPixelAnimation::NeoPixelAnimation(Adafruit_NeoPixel *strip) {
  this->strip = strip;
  reset();
}

void NeoPixelAnimation::reset() {
  frame = 0;
  for (int i=0; i < strip->numPixels(); i++) {
    strip->setPixelColor(i, strip->Color(0, 0, 0));
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return Adafruit_NeoPixel::Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return Adafruit_NeoPixel::Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return Adafruit_NeoPixel::Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


