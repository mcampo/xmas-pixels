#include "theaterchase_animation.h"

TheaterChaseAnimation::TheaterChaseAnimation(Adafruit_NeoPixel *strip, uint8_t r, uint8_t g, uint8_t b) : NeoPixelAnimation(strip) {
  setColor(r, g, b);
}

TheaterChaseAnimation::TheaterChaseAnimation(Adafruit_NeoPixel *strip) : TheaterChaseAnimation::TheaterChaseAnimation(strip, 255, 255, 255) {
}

void TheaterChaseAnimation::setColor(uint8_t r, uint8_t g, uint8_t b) {
  this->r = r;
  this->b = b;
  this->g = g;
}

void TheaterChaseAnimation::nextFrame() {
  for (int q=0; q < 3; q++) {
    for (int i=0; i < strip->numPixels(); i=i+3) {
      strip->setPixelColor(i+q, strip->Color(r, g, b));    //turn every third pixel on
    }
    strip->show();

    delay(60);

    for (int i=0; i < strip->numPixels(); i=i+3) {
      strip->setPixelColor(i+q, 0);        //turn every third pixel off
    }
  }
}

