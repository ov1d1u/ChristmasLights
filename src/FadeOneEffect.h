#include "Effect.h"
#include "FadeAllEffect.h"

#ifndef FADEONEEFFECT_H
#define FADEONEEFFECT_H

#define INITIAL_FADE_DURATION 6000

class FadeOneEffect: public Effect {
  private:
    int fadeStepInterval;
    int fadeDuration = INITIAL_FADE_DURATION;
    unsigned long lastMillis;
    unsigned long lastChangeMillis;
    unsigned long lastPausedMillis;
    int currentValue;
    int currentLED;
    FadeDirection fadeDirection = Up;
  public:
    FadeOneEffect(dimmerLamp *r, dimmerLamp *g, dimmerLamp *b, dimmerLamp *y) : Effect(r, g, b, y) {}
    void FadeOneEffect::loop();
    EffectType effectType();
};

#endif 
