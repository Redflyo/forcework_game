#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "physicalobject.h"

class Personnage: public PhysicalObject
{
protected:
    int itsLife;
    int itsAnimationImage;
    bool itsGround;
    float itsSpeedY;
public:
    Personnage();
    virtual void move(int anMovement) = 0;
    virtual void shoot() = 0;
    virtual void beShot() = 0;
    virtual void die() = 0;
    virtual void animate() = 0;
};

#endif // PERSONNAGE_H
