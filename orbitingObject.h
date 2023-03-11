#pragma once

#include "position.h"
#include "velocity.h"



class OrbitingObject
{
public:
    // Default constructor, sets position and velocity to 0.0
    OrbitingObject() : position(Position(0.0, 0.0)), velocity(Velocity(0.0, 0.0)) {}

    // Constructor
    OrbitingObject(double x, double y, double dx, double dy)
    { 
        position = Position(x, y); 
        velocity = Velocity(dx, dy);
    }

    // Only position constructor
    OrbitingObject(double x, double y)
    {
        position = Position(x, y);
    }

    void initialize() {}
    void breakThis() {}



private:
    Position position;
    Velocity velocity;
};