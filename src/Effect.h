#include <RBDdimmer.h>
#include "EffectType.h"

#ifndef EFFECT_H
#define EFFECT_H

class Effect {
  protected:
    dimmerLamp *redChannel;
    dimmerLamp *greenChannel;
    dimmerLamp *blueChannel;
    dimmerLamp *yellowChannel;
    unsigned long millisOffset;
  public:
    Effect(dimmerLamp *r, dimmerLamp *g, dimmerLamp *b, dimmerLamp *y) : redChannel(r), greenChannel(g), blueChannel(b), yellowChannel(y) { 
      millisOffset = ::millis();
    };
    ~Effect();
    unsigned long millis();
    virtual void loop();
    virtual EffectType effectType();
};

#endif
