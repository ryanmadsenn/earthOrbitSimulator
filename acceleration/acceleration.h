#pragma once

#include "../direction/direction.h"

using namespace std;


class Acceleration
{
public:
    Acceleration() : ddx(0.0), ddy(0.0) {}
    Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) {}
    Acceleration(double magnitude, const Direction& direction) : ddx(0.0), ddy(0.0)
    {
        setAccelerationDirection(magnitude, direction);
    }

    double getDDX() const { return ddx; }
    double getDDY() const { return ddy; }

    void setDDX(double ddx) { this->ddx = ddx; }
    void setDDY(double ddy) { this->ddy = ddy; }

    void addDDX(double ddx) { this->ddx += ddx; }
    void addDDY(double ddy) { this->ddy += ddy; }

    void setAccelerationDirection(double magnitude, const Direction& direction);

private:
    double ddx;
    double ddy;
};