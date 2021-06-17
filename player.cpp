#include "player.h"
#include <QDebug>

bool Player::getItsImpulsion() const
{
    return itsImpulsion;
}

bool Player::getItsGround() const
{
    return itsGround;
}


Player::Player()
{
    setItsLife(3);
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
    if(bloc.getItsBlockType() != 0 && bloc.getItsBlockType() != 1 && bloc.getItsBlockType() != 5)
    {
      if( getItsBlockX() >= bloc.getItsBlockX()-2 && getItsBlockX() <= bloc.getItsBlockX() +2)
      {
        if( getItsBlockY() >= bloc.getItsBlockY()-3 && getItsBlockY() <= bloc.getItsBlockY() +3)
        {
           arroundPlayer.push_back(bloc);

        }

    }
  }
  }
  if(itsMovement == 1)
  {
    setItsX(itsX-itsSpeedX);
    for(Block block: arroundPlayer)
    {
      if(isCollide(*this, block) == 1)setItsX(itsX+itsSpeedX);

    }
  }
  else if(itsMovement == 2)
  {

    setItsX(itsX+itsSpeedX);
    for(Block block: arroundPlayer)
    {
      if(isCollide(*this, block) == 1) setItsX(itsX-=itsSpeedX);
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





void Player::beShot()
{
    setItsLife(getItsLife()-1);
    if(getItsLife()==0)
    {
        die();
    }

}

void Player::die()
{
    setIsDead(true);
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

int Player::getGunY() const

{
    return itsHeight/3+itsY-5;
}











