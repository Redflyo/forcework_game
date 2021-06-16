#include "bullet.h"
///
/// \brief Bullet::Bullet
///

Bullet::Bullet(Personnage *owner, bool direction)
{
    itsOwner = owner;
    setItsWidth(5);
    setItsHeight(10);
    if(direction == true)
    {
        itsX = owner->getItsX();
        itsY = owner->getGunY();
        itsSpeedX*=-1;
    }
    else
    {
        itsX = owner->getItsX()+sizeBlock;
        itsY = owner->getGunY();
    }
}

Personnage *Bullet::getItsOwner() const
{
    return itsOwner;
}

void Bullet::move()
{

    itsX+=itsSpeedX;
}

void Bullet::animate()
{

}

