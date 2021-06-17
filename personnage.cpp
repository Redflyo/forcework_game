#include "personnage.h"

int Personnage::getItsAnimationImage() const
{
    return itsAnimationImage;
}


int Personnage::getGunY() const
{
    return itsHeight/3+itsY-5;
}


float Personnage::getItsSpeedY() const
{
    return itsSpeedY;
}
bool Personnage::getDirection() const
{
    return itsDirection;
}

void Personnage::setDirection(bool value)
{
    itsDirection = value;
}

int Personnage::getItsLife() const
{
    return itsLife;
}

void Personnage::setItsLife(int value)
{
    itsLife = value;
}

bool Personnage::getIsDead() const
{
    return isDead;
}

void Personnage::setIsDead(bool value)
{
    isDead = value;
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
