#pragma once

#include "../direction/direction.h"
#include "../acceleration/acceleration.h"
#include "math.h"

class Velocity
{
public:
    Velocity() : dx(0.0), dy(0.0) {}
    Velocity(double dx, double dy) : dx(dx), dy(dy) {}
    Velocity(const Velocity & velocity) : dx(velocity.dx), dy(velocity.dy) {}
    Velocity(double speed, const Direction& direction) : dx(0.0), dy(0.0)
    {
        setSpeedDirection(speed, direction);
    }
    Velocity& operator=(const Velocity & velocity)
    {
        dx = velocity.dx;
        dy = velocity.dy;
        return *this;
    }

    Velocity& operator+=(const Velocity& rhs)
    {
        addV(rhs);
        return *this;
    }

    Velocity& operator+=(const Acceleration& rhs);

    double getDx() const { return dx; }
    double getDy() const { return dy; }
    double getSpeed() const;
    Direction getDirection() const;

    void setDx(double dx) { this->dx = dx; }
    void setDy(double dy) { this->dy = dy; }
    void setVelocity(double dx, double dy) { this->dx = dx; this->dy = dy; }
    void setDxDy(double dx, double dy) { this->dx = dx; this->dy = dy; }
    void setDirection(const Direction& direction)
    {
        setSpeedDirection(getSpeed(), direction);
    }
    void setSpeed(double speed)
    {
        setSpeedDirection(speed, getDirection());
    }

    void addDx(double dx) { this->dx += dx; }
    void addDy(double dy) { this->dy += dy; }
    void addDxDy(double dx, double dy) { this->dx += dx; this->dy += dy; }
    void addV(const Velocity& velocity) { this->dx += velocity.getDx(); this->dy += velocity.getDy(); }

    void setSpeedDirection(double speed, const Direction& direction);

    void reverse()
    {
        dx *= -1.0;
        dy *= -1.0;
    }

private:
    double dx;
    double dy;
};