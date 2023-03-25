#pragma  once
#include <iostream>
#include <vector>
#include "../position/position.h"
#include "../uiDraw/uiDraw.h"
#include "../velocity/velocity.h"
#include "../direction/direction.h"

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
    Velocity velocityObject;
    Direction directionObject;
    bool dead = false;
    bool alive = true;
    bool defunct = false;

public:
    virtual ~OrbitingObject() = default;
    void initialize(Position position, double dx, double dy, double aRadians, double radius, string type);
    Position * getPosition();
    double getDx();
    double getDy();
    double getARadians();
    double getRadius();
    Velocity * getVelocity() { return &velocityObject; }
    Direction * getDirection() { return &directionObject; }
    string getType();

    void setVelocity(Velocity velocity) { velocityObject = velocity; }
    void setDirection(Direction direction) { directionObject = direction; }
    void setPosition(Position position) { this->position = position; }
    void setDx(double dx);
    void setDy(double dy);
    void setARadians(double aRadians);
    void setRadius(double radius);
    virtual void updateAngle(double rotation) {
        int num = random(0, 30000);
        if (num < 10) {
            defunct = true;
        }

        aRadians += defunct ? rotation * 20 : rotation;
    }
    virtual void draw() = 0;
    virtual void smash(vector<OrbitingObject *> * orbitingObjects) = 0;

    bool isDead() { return dead;}
    bool isAlive() { return alive;}
    void kill();
    void destroy(OrbitingObject * object);
};