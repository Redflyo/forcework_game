#ifndef BULLET_H
#define BULLET_H
#include "physicalobject.h"
#include "personnage.h"

class Bullet: public PhysicalObject
{
private:
    int itsSpeedX = 10;
    int itsSpeedY;
    int itsAnimationImage;
    Personnage *itsOwner;
    bool isHit = false;
    int animTime = 0;
public:
    void move();
    void animate();
    Bullet(Personnage *owner, bool direction);
    Personnage *getItsOwner() const;
    bool getIsHit() const;
    void setIsHit(bool value);
    int getAnimTime() const;
    void setAnimTime(int value);
    void setItsSpeedX(int value);
};

#endif // BULLET_H
