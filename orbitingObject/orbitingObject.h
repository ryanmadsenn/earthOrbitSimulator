#pragma  once
#include <iostream>
#include <vector>
#include "../position/position.h"
#include "uiDraw/uiDraw.h"

using namespace std;

class OrbitingObject {
protected:
    OrbitingObject();
    OrbitingObject(double x, double y) : position(Position(x, y)) {};
    Position position;
    double dx;
    double dy;
    double aRadians;
    double radius;
    string type;

public:
    ~OrbitingObject() {};
    void initialize(Position position, double dx, double dy, double aRadians, double radius, string type);
    Position * getPosition();
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
    virtual void smash(vector<OrbitingObject *> orbitingObjects) = 0;
};