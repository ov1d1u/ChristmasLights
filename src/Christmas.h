#include <RBDdimmer.h>
#include "Effect.h"
#include "FadeAllEffect.h"
#include "BlinkyBlinkEffect.h"
#include "BlinkyRowEffect.h"
#include "FadeOneEffect.h"
#include "StarryNightEffect.h"
#include "DomnDomnEffect.h"

#ifndef CHRISTMAS_H
#define CHRISTMAS_H

class Christmas {
  private:
    dimmerLamp *r, *g, *b, *y;
    Effect *currentEffect;
    unsigned long lastMillis;
  public:
    Christmas(dimmerLamp *r, dimmerLamp *g, dimmerLamp *b, dimmerLamp *y) : r(r), g(g), b(b), y(y) {};
    void begin();
    void loop();
};

#endif
