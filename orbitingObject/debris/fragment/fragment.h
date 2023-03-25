#pragma once
#include "../debris.h"
#include "../../../position/position.h"

class Fragment : public Debris {
private:
    int lifespan;
    int age = 0;

public:
    Fragment(Position position, double dx, double dy, double aRadians);

    virtual void draw() override;

    virtual void smash(vector<OrbitingObject *> * orbitingObjects) override;

    int getAge() const {
        return age;
    }

    int getLifespan() const {
        return lifespan;
    }

    void incrementAge() {
        age++;
    }
};
