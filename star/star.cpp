
#include "star.h"

/*******************************************************
 *
 *******************************************************/
Star::Star(Position ptStar, unsigned char phase)
{
    initialize(ptStar, phase);
}

void Star::initialize(Position ptStar, unsigned char phase)
{
    this->ptStar = ptStar;
    this->phase = phase;
}
