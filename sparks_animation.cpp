#include "sparks_animation.h"

SparksAnimation::SparksAnimation(Adafruit_NeoPixel *strip) : NeoPixelAnimation(strip) {
  r = g = b = 255;
}

void SparksAnimation::nextFrame() {
  if (frame == 0) {
    byte p = random(strip->numPixels());
    for (int i=0; i < 254; i=i+2) {
      strip->setPixelColor(p, strip->Color(r * i / 255, g * i / 255, b * i / 255));
      strip->show();
    }
    for (int i=255; i >= 0; i-=2) {
      strip->setPixelColor(p, strip->Color(r * i / 255, g * i / 255, b * i / 255));
      strip->show();
    }
    strip->setPixelColor(p, strip->Color(0, 0, 0));
    strip->show();
  } else {
    delay(random(20));
  }

  frame++;  
  if (frame >= random(20, 200)) {
    frame = 0;
  }
}

