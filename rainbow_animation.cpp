#include "rainbow_animation.h"

RainbowAnimation::RainbowAnimation(Adafruit_NeoPixel *strip) : NeoPixelAnimation(strip) {
}

void RainbowAnimation::nextFrame() {
  uint16_t i, j;
  j = frame;

  for(i=0; i<strip->numPixels(); i++) {
    strip->setPixelColor(i, Wheel((i+j) & 255));
  }
  strip->show();
  delay(20);

  frame++;
  if (frame > 255) {
    frame = 0;
  }
}


