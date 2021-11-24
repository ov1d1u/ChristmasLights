#include <RBDdimmer.h>
#include "Effect.h"

#ifndef FADEALLEFFECT_H
#define FADEALLEFFECT_H

#define INITIAL_FADE_DURATION 6000

enum FadeDirection { Up, Down };

class FadeAllEffect: public Effect {
  private:
    int fadeStepInterval;
    int fadeDuration = INITIAL_FADE_DURATION;
    unsigned long lastMillis;
    unsigned long lastChangeMillis;
    unsigned long lastPausedMillis;
    int currentValue;
    FadeDirection fadeDirection = Up;
  public:
    FadeAllEffect(dimmerLamp *r, dimmerLamp *g, dimmerLamp *b, dimmerLamp *y) : Effect(r, g, b, y) {}
    void FadeAllEffect::loop();
    EffectType effectType();
};

#endif
