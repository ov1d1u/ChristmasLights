#include <Arduino.h>
#include "BlinkyRowEffect.h"
#include "Limits.h"

#define SPEED_CHANGE_INTERVAL 15000

void BlinkyRowEffect::loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastMillis >= blinkInterval) {
    lastMillis = millis();

    redChannel->setPower(map(0, 0, 255, 0, MAX_RED));
    greenChannel->setPower(map(0, 0, 255, 0, MAX_GREEN));
    blueChannel->setPower(map(0, 0, 255, 0, MAX_BLUE));
    yellowChannel->setPower(map(0, 0, 255, 0, MAX_YELLOW));

    if (currentIteration == 0) {
      redChannel->setPower(map(255, 0, 255, 0, MAX_RED));
    } else if (currentIteration == 1) {
      greenChannel->setPower(map(255, 0, 255, 0, MAX_GREEN));
    } else if (currentIteration == 2) {
      blueChannel->setPower(map(255, 0, 255, 0, MAX_BLUE));
    } else if (currentIteration == 3) {
      yellowChannel->setPower(map(255, 0, 255, 0, MAX_YELLOW));
    }

    currentIteration++;

    if (currentIteration > 3) currentIteration = 0;

    if (currentMillis - lastChangeMillis >= SPEED_CHANGE_INTERVAL) {
      lastChangeMillis = currentMillis;
      blinkInterval -= 200;
      if (blinkInterval < 100) {
        blinkInterval = 1000;
      }
    }
  }
}

EffectType BlinkyRowEffect::effectType() { 
  return BlinkyRow; 
};
