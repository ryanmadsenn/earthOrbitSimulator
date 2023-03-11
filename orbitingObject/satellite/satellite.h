#include "../orbitingObject.h"

class Satellite : public OrbitingObject {
protected:
    Satellite();

public:
    virtual void draw() = 0;
    virtual void smash() = 0;
};
