#include <Arduino.h>
#include "FadeOneEffect.h"
#include "Limits.h"

#define MAX_CURRENT_VALUE 255
#define SPEED_CHANGE_INTERVAL 10000
#define PAUSE_DURATION 1000

void FadeOneEffect::loop() {
  unsigned long currentMillis = millis();
  if (currentValue == 1 && currentMillis - lastPausedMillis < PAUSE_DURATION) {
    return;
  }
  
  if (currentMillis - lastMillis >= fadeDuration/MAX_CURRENT_VALUE) {
    lastMillis = millis();

    if (currentValue < 0) {
      fadeDirection = Up;
      currentValue = 0;
      currentLED++;
      if (currentLED > 3) currentLED = 0;
      lastPausedMillis = lastMillis;
    } else if (currentValue > MAX_CURRENT_VALUE) {
      fadeDirection = Down;
      currentValue = MAX_CURRENT_VALUE;
    }

    if (currentLED == 0) {
      redChannel->setPower(map(currentValue, 0, 255, 0, MAX_RED));
    } else if (currentLED == 1) {
      greenChannel->setPower(map(currentValue, 0, 255, 0, MAX_GREEN));
    } else if (currentLED == 2) {
      blueChannel->setPower(map(currentValue, 0, 255, 0, MAX_BLUE));
    } else if (currentLED == 3) {
      yellowChannel->setPower(map(currentValue, 0, 255, 0, MAX_YELLOW));
    }

    if (fadeDirection == Up) currentValue++;
    else if (fadeDirection == Down) currentValue--;

    if (currentMillis - lastChangeMillis >= SPEED_CHANGE_INTERVAL) {
      lastChangeMillis = currentMillis;
      fadeDuration -= 2000;
      if (fadeDuration < 2000) {
        fadeDuration = INITIAL_FADE_DURATION;
      }
    }
  }
}

EffectType FadeOneEffect::effectType() { 
  return FadeOne; 
};
