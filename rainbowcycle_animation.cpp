#include "rainbowcycle_animation.h"

RainbowCycleAnimation::RainbowCycleAnimation(Adafruit_NeoPixel *strip) : NeoPixelAnimation(strip) {
}

void RainbowCycleAnimation::nextFrame() {
  uint16_t i, j;
  j = frame;

  for(i=0; i< strip->numPixels(); i++) {
    strip->setPixelColor(i, Wheel(((i * 256 / strip->numPixels()) + j) & 255));
  }
  strip->show();
  delay(10);

  frame++;
  if (frame > 255) {
    frame = 0;
  }
}


