#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "physicalobject.h"

class Personnage: public PhysicalObject
{
protected:
    int itsLife;
    int itsAnimationImage = 0;
    bool itsGround;
    float itsSpeedY;
    int itsMovement;
    int gunY;
public:

    Personnage();
    virtual ~Personnage();
    virtual void move() = 0;
    virtual void setMovement(int movement);
    virtual void shoot() = 0;
    virtual void beShot() = 0;
    virtual void die() = 0;
    virtual void animate() = 0;
    int getItsAnimationImage() const;
    int getGunY() const;
    void setGunY(int value);
};

#endif // PERSONNAGE_H
