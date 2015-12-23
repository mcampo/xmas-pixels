#include "fade_animation.h"

FadeAnimation::FadeAnimation(Adafruit_NeoPixel *strip, uint8_t r, uint8_t g, uint8_t b) : NeoPixelAnimation(strip) {
  setColor(r, g, b);
}

FadeAnimation::FadeAnimation(Adafruit_NeoPixel *strip) : FadeAnimation::FadeAnimation(strip, 255, 255, 255) {
}

void FadeAnimation::setColor(uint8_t r, uint8_t g, uint8_t b) {
  this->r = r;
  this->b = b;
  this->g = g;
}

void FadeAnimation::nextFrame() {
  int brightness = frame;
  uint32_t color;
  if (brightness <= 255) {
    color =  strip->Color(r * brightness / 255, g * brightness / 255, b * brightness / 255);
  } else {
    brightness = abs(512 - frame - 1);
    color =  strip->Color(r * brightness / 255, g * brightness / 255, b * brightness / 255);
  }
  
  for (int i=0; i < strip->numPixels(); i++) {
    strip->setPixelColor(i, color);
  }
  strip->show();
  delay(3);

  frame++;
  if (frame > 512) {
    frame = 0;
  }
}


