

#include "velocity.h"

Velocity& Velocity::operator+=(const Acceleration& rhs)
{
    dx += rhs.getDDX();
    dy += rhs.getDDY();
    return *this;
}

double Velocity::getSpeed() const
{
    return sqrt(dx * dx + dy * dy);
}

Direction Velocity::getDirection() const
{
    Direction direction;
    direction.setDirection(dx, dy);
    return direction;
}

void Velocity::setSpeedDirection(double speed, const Direction& direction)
{
    dx = speed * direction.getDx();
    dy = speed * direction.getDy();
}