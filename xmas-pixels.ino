#include <Adafruit_NeoPixel.h>
#include "animations.h"
#include "fade_animation.h"
#include "rainbow_animation.h"
#include "sparks_animation.h"
#include "theaterchase_animation.h"
#include "rainbowcycle_animation.h"

#define PIN 6
#define BUTTON_PIN 2
#define ANIMATION_CYCLE_INTERVAL 30000

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN);
FadeAnimation fadeAnimation(&strip, 150, 150, 255);
RainbowAnimation rainbowAnimation(&strip);
SparksAnimation sparksAnimation(&strip);
TheaterChaseAnimation theaterChaseAnimation(&strip);
RainbowCycleAnimation rainbowCycleAnimation(&strip);
NeoPixelAnimation *animations[] = {&rainbowAnimation, &fadeAnimation, &sparksAnimation, &theaterChaseAnimation, &rainbowCycleAnimation};
byte animationCount = (sizeof(animations) / sizeof(NeoPixelAnimation *));

bool buttonPreviousState = HIGH;
byte animationIndex = 0;
unsigned long timeForNextAnimation = 0;
bool cycleAnimations = true;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  strip.begin();
  strip.setBrightness(20);
  strip.show();

  timeForNextAnimation = millis() + ANIMATION_CYCLE_INTERVAL;
}

void loop() {
  if (cycleAnimations) {
    checkTimeForNextAnimation();
  }
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
      buttonPressed();
      delay(20);
    }
  }
  buttonPreviousState = buttonNewState;
}

void buttonPressed() {
  if(cycleAnimations) {
    cycleAnimations = false;
    return;
  }
  if (animationIndex == animationCount - 1) { //last animation
    cycleAnimations = true;
    timeForNextAnimation = millis() + ANIMATION_CYCLE_INTERVAL;
  }
  nextAnimation();
}

void checkTimeForNextAnimation() {
  unsigned long currentTime = millis();
  if (currentTime >= timeForNextAnimation) {
    nextAnimation();
    timeForNextAnimation = millis() + ANIMATION_CYCLE_INTERVAL;
  }
}

void nextAnimation() {
  animationIndex++;
  if (animationIndex >= animationCount) {
    animationIndex = 0;
  }
  animations[animationIndex]->reset();
}

