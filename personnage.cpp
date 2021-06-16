#include "personnage.h"

int Personnage::getItsAnimationImage() const
{
    return itsAnimationImage;
}

int Personnage::getGunY() const
{
    return itsHeight/3+itsY-5;
}

void Personnage::setGunY(int value)
{
    gunY = value;
}
float Personnage::getItsSpeedY() const
{
    return itsSpeedY;
}
bool Personnage::getDirection() const
{
    return direction;
}

void Personnage::setDirection(bool value)
{
    direction = value;
}

Personnage::Personnage()
{

}

Personnage::~Personnage()
{
    
}

void Personnage::setMovement(int movement)
{
    itsMovement = movement;
}
