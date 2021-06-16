#include "player.h"
#include <QDebug>

Player::Player()
{

}

Player::~Player()
{

}
void Player::move(vector<Block> itsMap)
{
  vector<Block*> arroundPlayer;
  arroundPlayer.clear();
  for(Block bloc: itsMap)
  {
    if(bloc.getItsBlockType() != 0)
    {
      if( getItsBlockX() >= bloc.getItsBlockX()-2 && getItsBlockX() <= bloc.getItsBlockX() +2)
      {
        if( getItsBlockY() >= bloc.getItsBlockY()-3 && getItsBlockY() <= bloc.getItsBlockY() +2)
        {
           arroundPlayer.push_back(&bloc);
  qDebug() << bloc.getItsX() << " " <<  bloc.getItsY();
        }
      }
    }
  }
  if(itsMovement == 1)
  {
    itsX -=2;
    for(Block *block: arroundPlayer)
    {
      if(isCollideH(*this, *block) == 1) itsX+=2;
    }
  }
  else if(itsMovement == 2)
  {
    itsX += 2;
    for(Block *block: arroundPlayer)
    {
      if(isCollideH(*this, *block) == 2) itsX-=2;
    }
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
    if (itsMovement == 3)
    {
        itsAnimationImage = 3;
    }

}


bool Player::isWin()
{

}









