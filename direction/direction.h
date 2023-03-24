#pragma once

#include "math.h"

inline double degreesFromRadians(double radians)
{
//    return radians * 180.0 / M_PI;
    return 360.0 * (radians / (2.0 * M_PI));
}

inline double radiansFromDegrees(double degrees)
{
//    return degrees * M_PI / 180.0;
    return (degrees / 360.0) * (2.0 * M_PI);
}

class Direction
{
public:
    Direction() : radians(0.0) {}
    Direction(double degree) : radians(0.0)
    {
        radians = radiansFromDegrees(degree);
    }
    Direction(const Direction & direction) : radians(direction.radians) {}
    Direction& operator=(const Direction & direction)
    {
        radians = direction.radians;
        return *this;
    }

    Direction operator+(double degree) const
    {
        return Direction(getDegrees() + degree);
    }
    Direction operator+(Direction direction) const
    {
        direction.rotate(radians);
        return direction;
    }

    double getDx() const { return cos(radians); }
    double getDy() const { return sin(radians); }
    double getRadians() const { return radians; }
    double getDegrees() const { return degreesFromRadians(radians); }

    bool isRight() const { return radians > 0.0 && radians < M_PI; }
    bool isLeft() const { return radians < 0.0 && radians > -M_PI; }

    void setRadians(double radians)
    {
        if (radians >= 0.0)
        {
            double rotation = (double)(int)((M_PI + radians) / (2.0 * M_PI));
            radians -= rotation * 2.0 * M_PI;
        }
        else
        {
            double rotation = (double)(int)((M_PI - radians) / (2.0 * M_PI));
            radians += rotation * 2.0 * M_PI;
        }
        this->radians = radians;
    }

    void setDegrees(double degrees)
    {
        setRadians(radiansFromDegrees(degrees));
    }


    void setDxDy(double dx, double dy)
    {
        radians = atan2(dy, dx);
    }

    void setDirection(double dx, double dy)
    {
        radians = atan2(dy, dx);
    }

    void setDown() { radians = M_PI; }
    void setUp() { radians = 0.0; }
    void setRight() { radians = M_PI_2; }
    void setLeft() { radians = -M_PI_2; }
    void reverse() { radians += M_PI; }

    void rotate(double amount)
    {
        radians += amount;
    }

private:
    double radians;
};