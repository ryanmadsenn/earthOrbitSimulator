#pragma once

class Earth
{
private:
    Position ptEarth;
    double angleEarth;

public:
    Earth() : ptEarth(0.0, 0.0), angleEarth(0.0) {}

    // Getters
    double getAngle() { return angleEarth; }
    Position getPosition() { return ptEarth; }

    // Setters
    void setAngle(double angle) { angleEarth = angle; }
    void setPosition(Position position) { ptEarth = position; }

    // Other methods
    void updateAngle(double rotation) { angleEarth += rotation; }
    void draw() { drawEarth(ptEarth, angleEarth); }
};