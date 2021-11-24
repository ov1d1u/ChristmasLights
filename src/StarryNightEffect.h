#include "Effect.h"

#ifndef STARRYNIGHTEFFECT_H
#define STARRYNIGHTEFFECT_H

enum StarryNightState { StarOn, StarOff };

class StarryNightEffect: public Effect {
  private:
    int interval = random(250, 400);
    StarryNightState state;
    unsigned long lastMillis;
    unsigned long lastBlinkMillis;
  public:
    StarryNightEffect(dimmerLamp *r, dimmerLamp *g, dimmerLamp *b, dimmerLamp *y) : Effect(r, g, b, y) {}
    void StarryNightEffect::loop();
    EffectType effectType();
};

#endif
