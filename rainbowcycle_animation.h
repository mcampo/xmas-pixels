#include "animations.h"

class RainbowCycleAnimation : public NeoPixelAnimation {
  
  public:
    RainbowCycleAnimation(Adafruit_NeoPixel *strip);
    void nextFrame();

};

