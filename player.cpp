#include "player.h"

Player::Player()
{

}

Player::~Player()
{

}
void Player::move()
{
    if(itsMovement == 1)
    {
        itsX +=5;
    }
    if(itsMovement == 2)
    {
        itsX -= 5;
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

}
