#include <Adafruit_NeoPixel.h>
#include "animations.h"
#include "fade_animation.h"
#include "rainbow_animation.h"
#include "sparks_animation.h"
#include "theaterchase_animation.h"
#include "rainbowcycle_animation.h"

#define PIN 6
#define BUTTON_PIN 2

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN);
FadeAnimation fadeAnimation(&strip, 150, 150, 255);
RainbowAnimation rainbowAnimation(&strip);
SparksAnimation sparksAnimation(&strip);
TheaterChaseAnimation theaterChaseAnimation(&strip);
RainbowCycleAnimation rainbowCycleAnimation(&strip);
NeoPixelAnimation *animations[] = {&rainbowAnimation, &fadeAnimation, &sparksAnimation, &theaterChaseAnimation, &rainbowCycleAnimation};

bool buttonPreviousState = HIGH;
byte animationIndex = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  strip.begin();
  strip.setBrightness(20);
  strip.show();
}

void loop() {
  checkButton();
  animations[animationIndex]->nextFrame();
}

void checkButton() {
  bool buttonNewState = digitalRead(BUTTON_PIN);
  if (buttonNewState == LOW && buttonPreviousState == HIGH) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    buttonNewState = digitalRead(BUTTON_PIN);
    if (buttonNewState == LOW) {
      animationIndex++;
      if (animationIndex >= (sizeof(animations) / sizeof(NeoPixelAnimation *))) {
        animationIndex = 0;        
      }
      animations[animationIndex]->reset();
    }
  }
  buttonPreviousState = buttonNewState;
}

