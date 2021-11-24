#include <Arduino.h>
#include "Christmas.h"

#define EFFECT_CHANGE_INTERVAL 30000

void Christmas::begin() {
  randomSeed(analogRead(0));
  currentEffect = new FadeAllEffect(r, g, b, y);
}

void Christmas::loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastMillis >= EFFECT_CHANGE_INTERVAL) {
    lastMillis = currentMillis;

    EffectType effectType = currentEffect->effectType();
    delete currentEffect;

    switch (effectType) {
      case BlinkyBlink:
        currentEffect = new BlinkyRowEffect(r, g, b, y);
        break;
      case BlinkyRow:
        currentEffect = new StarryNightEffect(r, g, b, y);
        break;
      case StarryNight:
        currentEffect = new DomnDomnEffect(r, g, b, y);
        break;
      case DomnDomn:
        currentEffect = new FadeAllEffect(r, g, b, y);
        break;
      case FadeAll:
        currentEffect = new FadeOneEffect(r, g, b, y);
        break;
      case FadeOne:
        currentEffect = new BlinkyBlinkEffect(r, g, b, y);
        break;
      default:
        currentEffect = new StarryNightEffect(r, g, b, y);
        break;
    }
  }

  currentEffect->loop();
}
