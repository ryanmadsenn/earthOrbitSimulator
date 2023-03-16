
#include "star.h"

Star::Star()
{
    ptStar = Position(random(0, 999), random(0, 999));
    phase = random(0, 224);
}