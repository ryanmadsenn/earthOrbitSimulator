/*************************************************************
 * Header File:
 *    Star: Class for a star
 * Author:
 *    Vega Erick Penafiel, Madsen Ryan, and Bueze Nwokolo
 *************************************************************/
#pragma once

#include "../uiDraw/uiDraw.h"

class Star
{
private:
    Position ptStar;
    unsigned char phase;
    void initialize(Position ptStar, unsigned char phase);

public:
    Star(Position ptStar, unsigned char phase);
    void draw() { drawStar(ptStar, phase++); }
};