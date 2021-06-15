#include "personnage.h"

int Personnage::getItsAnimationImage() const
{
    return itsAnimationImage;
}

int Personnage::getGunY() const
{
    return gunY;
}

void Personnage::setGunY(int value)
{
    gunY = value;
}
Personnage::Personnage()
{
    gunY = (itsHeight)/4;
}

Personnage::~Personnage()
{
    
}

void Personnage::setMovement(int movement)
{
    itsMovement = movement;
}
