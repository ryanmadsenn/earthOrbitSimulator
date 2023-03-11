#include <iostream>
#include <vector>
#include "position/position.h"
#include "../uiDraw.h"

using namespace std;

class OrbitingObject {
protected:
    OrbitingObject();
    Position position;
    double dx;
    double dy;
    double aRadians;
    double radius;
    string type;

public:
    void initialize(Position position, double dx, double dy, double aRadians, double radius, string type);
    Position getPosition();
    double getDx();
    double getDy();
    double getARadians();
    double getRadius();
    string getType();
    void setPosition(Position position);
    void setDx(double dx);
    void setDy(double dy);
    void setARadians(double aRadians);
    void setRadius(double radius);
    virtual void draw() = 0;
    virtual void smash() = 0;
};