#pragma once

#include <vector>
#include "uiDraw/uiDraw.h"
using namespace std;

class Projectile
{
private:
    Position ptProjectile;
    double angleProjectile;
    double velocity;
    double projectileAge;
    vector<Position> path;

public:
    Projectile() {}
    Projectile(Position ptProjectile, double angleProjectile, double velocity);

    void reset(Position& pt, double angle, double velocity);

    // Setters
    void setAngle(double angle) { angleProjectile = angle; }

//    void move();

    void draw() { drawProjectile(ptProjectile); }
};