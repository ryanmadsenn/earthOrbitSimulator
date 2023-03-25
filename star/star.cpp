
#include "star.h"

/*******************************************************
 * Description: Constructor for the Star class.
 *******************************************************/
Star::Star(Position ptStar, unsigned char phase)
{
    initialize(ptStar, phase);
}

/*******************************************************
 * Description: Initializes the Star class.
 *******************************************************/
void Star::initialize(Position ptStar, unsigned char phase)
{
    this->ptStar = ptStar;
    this->phase = phase;
}
