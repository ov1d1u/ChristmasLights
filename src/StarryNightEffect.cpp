#include <Arduino.h>
#include "StarryNightEffect.h"
#include "Limits.h"

#define BLINK_DURATION 10

void StarryNightEffect::loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastMillis >= interval) {
    lastMillis = millis();

    interval = random(100, 600);
    int currentLED = random(0, 4);

    if (currentLED == 0) {
      redChannel->setPower(map(255, 0, 255, 0, MAX_RED));
    } else if (currentLED == 1) {
      greenChannel->setPower(map(255, 0, 255, 0, MAX_GREEN));
    } else if (currentLED == 2) {
      blueChannel->setPower(map(255, 0, 255, 0, MAX_BLUE));
    } else if (currentLED == 3) {
      yellowChannel->setPower(map(255, 0, 255, 0, MAX_YELLOW));
    }

    state = StarOn;
    
  } else if (state == StarOn && currentMillis - lastMillis >= BLINK_DURATION) {
    state = StarOff;
    
    redChannel->setPower(map(0, 0, 255, 0, MAX_RED));
      greenChannel->setPower(map(0, 0, 255, 0, MAX_GREEN));
      blueChannel->setPower(map(0, 0, 255, 0, MAX_BLUE));
      yellowChannel->setPower(map(0, 0, 255, 0, MAX_YELLOW));
  }
}

EffectType StarryNightEffect::effectType() { 
  return StarryNight; 
};
