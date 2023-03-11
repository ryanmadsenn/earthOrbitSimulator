#include "simulator.h"

class FakeSimulator : public Simulator {
public:
    FakeSimulator();

    virtual void initialize();

    virtual bool checkForCollisions() override;

    virtual void handleCollision(OrbitingObject *obj1, int obj1index, OrbitingObject *obj2, int obj2index) override;

    virtual void updateObjects();
};
