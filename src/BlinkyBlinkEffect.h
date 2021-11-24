#include "Effect.h" 

#ifndef BLINKYEFFECT_H
#define BLINKYEFFECT_H

enum BlinkMode { Normal, Duo };

class BlinkyBlinkEffect: public Effect {
  private:
    int currentIteration;
    BlinkMode blinkMode = Normal;
    unsigned long lastMillis;
    unsigned long lastChangeMillis;
  public:
    BlinkyBlinkEffect(dimmerLamp *r, dimmerLamp *g, dimmerLamp *b, dimmerLamp *y) : Effect(r, g, b, y) {}
    void BlinkyBlinkEffect::loop();
    EffectType effectType();
};

#endif
