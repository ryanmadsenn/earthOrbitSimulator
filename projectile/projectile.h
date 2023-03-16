#pragma once

#include "../uiDraw/uiDraw.h"
#include <vector>
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
    Projectile();

    // Setters
    void setAngle(double angle) { angleProjectile = angle; }

    void move(double time);

    void draw() { drawProjectile(ptProjectile); }
};