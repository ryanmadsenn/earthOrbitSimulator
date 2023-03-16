#pragma once

#include "../position/position.h"
#include "../uiDraw/uiDraw.h"
#include <vector>

using namespace std;

class Projectile
{
private:
    Position ptProjectile;
    double angleProjectile;
    double velocity;
    double age;
    vector<Position> path;

public:
    Projectile();

    // Setters
    void setAngle(double angle) { angleProjectile = angle; }

    void move(double time);

    void draw() { drawProjectile(ptProjectile); }
};