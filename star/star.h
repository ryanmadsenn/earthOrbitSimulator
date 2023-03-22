#pragma once

#include "../uiDraw/uiDraw.h"

using namespace std;

class Star
{
private:
    Position ptStar;
    unsigned char phase;
    void initialize(Position ptStar, unsigned char phase);

public:
    Star(Position ptStar, unsigned char phase);
    void reset(Position& pt);
    void draw() { drawStar(ptStar, phase); };
};