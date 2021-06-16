#include "personnage.h"

int Personnage::getItsAnimationImage() const
{
    return itsAnimationImage;
}


bool Personnage::getItsTurn() const
{
    return itsTurn;
}

void Personnage::setItsTurn(bool value)
{
    itsTurn = value;
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
