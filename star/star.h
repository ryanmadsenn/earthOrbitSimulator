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

    void draw() { drawStar(ptStar, phase); };
};