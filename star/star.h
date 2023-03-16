#pragma once

#include "../uiDraw/uiDraw.h"

using namespace std;

class Star
{
private:
    Position ptStar;
    unsigned char phase;

public:
    Star();

    void reset(Position& pt);


    void draw() { drawStar(ptStar, phase); };
};