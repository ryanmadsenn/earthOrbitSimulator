#pragma once

class Earth
{
private:
    Position ptEarth;
    double angleEarth;

public:
    Earth() : ptEarth(0.0, 0.0), angleEarth(0.0) {}

    void updateAngle(double rotation) { angleEarth += rotation; }

    void draw() { drawEarth(ptEarth, angleEarth); }
};