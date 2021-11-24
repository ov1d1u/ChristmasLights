#include "Effect.h" 

#ifndef DOMNDOMNEFFECT_H
#define DOMNDOMNEFFECT_H

class DomnDomnEffect: public Effect {
  private:
    unsigned long millisOffset;
    unsigned long pauseMillis;
    int verse;
  public:
    DomnDomnEffect(dimmerLamp *r, dimmerLamp *g, dimmerLamp *b, dimmerLamp *y) : Effect(r, g, b, y) {}
    void DomnDomnEffect::loop();
    EffectType effectType();
};

#endif
