#include "player.h"
#include <QDebug>

Player::Player()
{

}

void Player::resetJump()
{
    itsImpulsion = false;
    itsTimeOfJump = 0;
    itsPowerImpulsion = 0;
}

void Player::jump()
{
    if(itsGround)
    {
        itsImpulsion = true;
        itsPowerImpulsion = 0.5;
    }
}

Player::~Player()
{

}
void Player::move(vector<Block> & itsMap)
{
  vector<Block> arroundPlayer;
  arroundPlayer.clear();
  for(Block bloc: itsMap)
  {
    if(bloc.getItsBlockType() != 0)
    {
      if( getItsBlockX() >= bloc.getItsBlockX()-2 && getItsBlockX() <= bloc.getItsBlockX() +2)
      {
        if( getItsBlockY() >= bloc.getItsBlockY()-3 && getItsBlockY() <= bloc.getItsBlockY() +3)
        {
           arroundPlayer.push_back(bloc);
           qDebug() << bloc.getItsX() << " " <<  bloc.getItsY();
        }
      }
    }
  }
  if(itsMovement == 1)
  {
    setItsX(itsX-2);
    for(Block block: arroundPlayer)
    {
      if(isCollide(*this, block) == 1)setItsX(itsX+2);
    }
  }
  else if(itsMovement == 2)
  {
    setItsX(itsX+2);
    for(Block block: arroundPlayer)
    {
      if(isCollide(*this, block) == 1) setItsX(itsX-=2);
    }
  }
  itsGround = false;
  itsSpeedY +=gravity;

  if(itsImpulsion)
  {
      itsTimeOfJump++;

      itsSpeedY-=itsPowerImpulsion;
  }
  else
  {
  }
  if(itsTimeOfJump > 20)
  {
      resetJump();
  }

  if(itsSpeedY < 0)
  {
      int lastY = itsY;
      setItsY(itsY+itsSpeedY);
      for(Block block: arroundPlayer)
      {
          if(isCollide(*this, block) == 1)
          {
              setItsY(lastY) ;
              itsSpeedY=0;
              resetJump();
          }
      }


  }
  else if(itsSpeedY > 0)
  {
      setItsY(itsY+itsSpeedY);
      for(Block block: arroundPlayer)
      {
          if(isCollide(*this, block) == 1)
          {
              itsGround = true ;
              itsSpeedY =0;
              resetJump();
              setItsY(block.getItsY() - itsHeight);
          }
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

}


bool Player::isWin()
{

}









