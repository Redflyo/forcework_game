#ifndef BULLET_H
#define BULLET_H
#include "physicalobject.h"
#include "personnage.h"

class Bullet: public PhysicalObject
{
private:
    int itsSpeedX;
    int itsSpeedY;
    int itsAnimationImage;
    Personnage *itsOwner;
public:
    void move();
    void animate();
    Bullet(Personnage *owner);
    Personnage *getItsOwner() const;
};

#endif // BULLET_H
