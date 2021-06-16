#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "physicalobject.h"
#include "block.h"

class Personnage: public PhysicalObject
{
protected:
    int itsLife;
    int itsAnimationImage = 0;
    float itsSpeedY=0;
    int itsMovement;
    bool direction = false;
    int gunY;
public:

    Personnage();
    virtual ~Personnage();
    virtual void move(std::vector<Block> & itsMap) = 0;
    virtual void setMovement(int movement);
    virtual void shoot() = 0;
    virtual void beShot() = 0;
    virtual void die() = 0;
    virtual void animate() = 0;
    int getItsAnimationImage() const;
    virtual int getGunY() const = 0;
    void setGunY(int value);
    float getItsSpeedY() const;
    bool getDirection() const;
    void setDirection(bool value);
    int getItsLife() const;
    void setItsLife(int value);
};

#endif // PERSONNAGE_H
