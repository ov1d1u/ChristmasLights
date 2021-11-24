#include "Effect.h" 

#ifndef BLINKYROWEFFECT_H
#define BLINKYROWEFFECT_H

class BlinkyRowEffect: public Effect {
  private:
    int currentIteration;
    int blinkInterval = 1000;
    unsigned long lastMillis;
    unsigned long lastChangeMillis;
  public:
    BlinkyRowEffect(dimmerLamp *r, dimmerLamp *g, dimmerLamp *b, dimmerLamp *y) : Effect(r, g, b, y) {}
    void BlinkyRowEffect::loop();
    EffectType effectType();
};

#endif
