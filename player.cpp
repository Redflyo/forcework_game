#include "player.h"

Player::Player()
{

}

Player::~Player()
{

}
void Player::move()
{
    // left
    if(itsMovement == 1)
    {
        setItsX(itsX -2);
    }
    //right
    if(itsMovement == 2)
    {
        setItsX(itsX - 2);
    }

}



void Player::shoot()
{

}

void Player::beShot()
{

}

void Player::die()
{

}

void Player::animate()
{
    if(itsMovement == 1)
    {
        itsAnimationImage = 1;
    }
    //right
    if(itsMovement == 2)
    {
        itsAnimationImage = 2;
    }
    if (itsMovement == 0)
    {
        itsAnimationImage = 0;
    }

}
