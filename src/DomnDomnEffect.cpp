#include <Arduino.h>
#include "DomnDomnEffect.h"
#include "Limits.h"

#define BLINK_TIME 200
#define PAUSE_TIME 600

int programme[] = {0, 800, 1600, 2000, 2400};

void DomnDomnEffect::loop() {
  unsigned long currentMillis = millis();

  if (pauseMillis && currentMillis - pauseMillis <= PAUSE_TIME) {
    return;
  }

  pauseMillis = 0;
  
  if (currentMillis - millisOffset >= programme[verse]) {
    if (currentMillis - millisOffset <= programme[verse] + BLINK_TIME) {
      redChannel->setPower(map(255, 0, 255, 0, MAX_RED));
      greenChannel->setPower(map(255, 0, 255, 0, MAX_GREEN));
      blueChannel->setPower(map(255, 0, 255, 0, MAX_BLUE));
      yellowChannel->setPower(map(255, 0, 255, 0, MAX_YELLOW));
    } else {
      redChannel->setPower(map(0, 0, 255, 0, MAX_RED));
      greenChannel->setPower(map(0, 0, 255, 0, MAX_GREEN));
      blueChannel->setPower(map(0, 0, 255, 0, MAX_BLUE));
      yellowChannel->setPower(map(0, 0, 255, 0, MAX_YELLOW));

      verse++;

      if (verse > 4) {
        pauseMillis = currentMillis;
        millisOffset = currentMillis + PAUSE_TIME;
        verse = 0;
      }
    }
  }
}

EffectType DomnDomnEffect::effectType() { 
  return DomnDomn; 
};
