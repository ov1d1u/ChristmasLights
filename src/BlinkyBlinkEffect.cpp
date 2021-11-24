#include <Arduino.h>
#include "BlinkyBlinkEffect.h"
#include "Limits.h"

#define BLINK_INTERVAL 200
#define DUO_BLINK_INTERVAL 100

void BlinkyBlinkEffect::loop() {
  unsigned long currentMillis = millis();

  if (blinkMode == Normal) {
    if (currentMillis - lastMillis >= BLINK_INTERVAL) {
      lastMillis = millis();

      redChannel->setPower(map(0, 0, 255, 0, MAX_RED));
      greenChannel->setPower(map(0, 0, 255, 0, MAX_GREEN));
      blueChannel->setPower(map(0, 0, 255, 0, MAX_BLUE));
      yellowChannel->setPower(map(0, 0, 255, 0, MAX_YELLOW));
  
      if (currentIteration % 4 == 0) {
        redChannel->setPower(map(255, 0, 255, 0, MAX_RED));
      } else if (currentIteration % 2 == 0) {
        blueChannel->setPower(map(255, 0, 255, 0, MAX_BLUE));
      } else if (currentIteration % 3 == 0) {
        yellowChannel->setPower(map(255, 0, 255, 0, MAX_YELLOW));
      } else {
        greenChannel->setPower(map(255, 0, 255, 0, MAX_GREEN));
      }
  
      currentIteration++;
  
      if (currentIteration != 0 && currentIteration % 12 == 0) {
        blinkMode = Duo;
        currentIteration = 0;
        lastMillis = 0;
      }
    }
  } else if (blinkMode == Duo) {
    if (currentMillis - lastMillis >= DUO_BLINK_INTERVAL) {
      lastMillis = millis();
      
      if (currentIteration % 2 == 0) {
        redChannel->setPower(map(0, 0, 255, 0, MAX_RED));
        greenChannel->setPower(map(255, 0, 255, 0, MAX_GREEN));
        blueChannel->setPower(map(0, 0, 255, 0, MAX_BLUE));
        yellowChannel->setPower(map(255, 0, 255, 0, MAX_YELLOW));
      } else {
        redChannel->setPower(map(255, 0, 255, 0, MAX_RED));
        greenChannel->setPower(map(0, 0, 255, 0, MAX_GREEN));
        blueChannel->setPower(map(255, 0, 255, 0, MAX_BLUE));
        yellowChannel->setPower(map(0, 0, 255, 0, MAX_YELLOW));
      }

      if (currentIteration != 0 && currentIteration % 8 == 0) {
        blinkMode = Normal;
        lastMillis = 0;
        currentIteration = 0;
      }

      currentIteration++;
    }
  }
}

EffectType BlinkyBlinkEffect::effectType() { 
  return BlinkyBlink;
};
