#include <Arduino.h>
#include "Effect.h"

unsigned long Effect::millis() {
  return ::millis() - millisOffset;
}

Effect::~Effect() {
  redChannel->setPower(map(255, 1, 255, 20, 0));
  greenChannel->setPower(map(255, 1, 255, 20, 0));
  blueChannel->setPower(map(255, 1, 255, 20, 0));
  yellowChannel->setPower(map(255, 1, 255, 20, 0));
}

EffectType Effect::effectType() { 
  return Unknown;
};

void Effect::loop() {
  
}
