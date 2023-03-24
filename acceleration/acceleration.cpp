

#include "acceleration.h"

void Acceleration::setAccelerationDirection(double magnitude, const Direction& direction)
{
    ddx = magnitude * direction.getDx();
    ddy = magnitude * direction.getDy();
}