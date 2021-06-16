#include "personnage.h"

int Personnage::getItsAnimationImage() const
{
    return itsAnimationImage;
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

int Personnage::getItsLife() const
{
    return itsLife;
}

void Personnage::setItsLife(int value)
{
    itsLife = value;
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
