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
        itsX = owner->getItsX()-5;
        itsY = owner->getGunY();
        itsSpeedX*=-1;
    }
    else
    {
        itsX = owner->getItsX()+sizeBlock+4;
        itsY = owner->getGunY();
    }
}

Personnage *Bullet::getItsOwner() const
{
    return itsOwner;
}

bool Bullet::getIsHit() const
{
    return isHit;
}

void Bullet::setIsHit(bool value)
{
    isHit = value;
}

int Bullet::getAnimTime() const
{
    return animTime;
}

void Bullet::setAnimTime(int value)
{
    animTime = value;
}

void Bullet::setItsSpeedX(int value)
{
    itsSpeedX = value;
}

int Bullet::getItsSpeedX() const
{
    return itsSpeedX;
}

void Bullet::move()
{
    
    itsX+=itsSpeedX;
}

void Bullet::animate()
{
    if(getIsHit())animTime++;
}

