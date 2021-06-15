#include "personnage.h"

int Personnage::getItsAnimationImage() const
{
    return itsAnimationImage;
}

float Personnage::getItsSpeedY() const
{
    return itsSpeedY;
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
