#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "physicalobject.h"
#include "block.h"

class Personnage: public PhysicalObject
{
protected:
    int itsLife;
    int itsAnimationImage = 0;
    bool itsGround;
    //bool itsTurn = false; // false pour droite et true pour gauche
    float itsSpeedY=0;
    int itsMovement;
    int itsSpeedX = 2;
    bool itsDirection = false;
    int gunY;
    bool isDead = false;
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
   // bool getItsTurn() const;
   // void setItsTurn(bool value);
    virtual int getGunY() const = 0;
    void setGunY(int value);
    float getItsSpeedY() const;
    bool getDirection() const;
    void setDirection(bool value);
    int getItsLife() const;
    void setItsLife(int value);
    bool getIsDead() const;
    void setIsDead(bool value);
};

#endif // PERSONNAGE_H
