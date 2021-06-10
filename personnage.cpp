#include "personnage.h"

int Personnage::getItsAnimationImage() const
{
    return itsAnimationImage;
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
