#include "ia.h"
#include <cmath>

int IA::getRoundBlockY() const
{
    return roundBlockY;
}

int IA::getRoundBlockXBegin() const
{
    return roundBlockXBegin;
}

int IA::getRoundBlockXEnd() const
{
    return roundBlockXEnd;
}

int IA::getRoundBlockXNow() const
{
    return roundBlockXNow;
}

bool IA::getItsMoveOrNot() const
{
    return itsMoveOrNot;
}

int IA::getItsTimeD() const
{
    return itsTimeD;
}

void IA::setItsTimeD(int value)
{
    itsTimeD = value;
}

int IA::getItsTimeG() const
{
    return itsTimeG;
}

void IA::setItsTimeG(int value)
{
    itsTimeG = value;
}

int IA::getSwitchMove() const
{
    return switchMove;
}

void IA::setAnimationDead(bool value)
{
    animationDead = value;
}

bool IA::getAnimationDead() const
{
    return animationDead;
}

IA::IA(int blockXBegin,int blockXEnd,int blockYRound)
{
    roundBlockXBegin = blockXBegin;
    roundBlockXEnd = blockXEnd;
    roundBlockY = blockYRound;
    roundBlockXNow = roundBlockXBegin;
    setItsX(blockToPixel(roundBlockXNow));
    setItsY(blockToPixel(roundBlockY));
    roundXBegin = blockToPixel(roundBlockXBegin);
    roundXEnd = blockToPixel(roundBlockXEnd);

    if (blockXBegin == blockXEnd)
    {
        itsMoveOrNot = false;
        forNoMove = true;
    }
    else
    {
        itsMoveOrNot = true;
    }
    setItsLife(3);



}

IA::~IA()
{

}

void IA::move(std::vector<Block> & itsMap)
{
    if (itsX<roundXBegin)
    {
        setDirection(false);
        switchMove = 2;
    }
    if(itsX>roundXEnd)
    {
        setDirection(true);
        switchMove = 1;

    }

    if (stop == false)
    {

        if (roundBlockXBegin != roundBlockXEnd)
        {
            // left
            if (getDirection() == true)
            {

                setItsX( itsX -2 );

            }

            //right
            if (getDirection()==false )
            {

                setItsX( itsX +2 );
            }
        }
    }
    else
    {
        switchMove = 0;
    }
    roundBlockXNow = pixelToBlock(itsX);


}


void IA::shoot()
{
    itsTimerCanShoot = 1;
}

void IA::beShot()
{
    setItsLife(getItsLife()-1);

    if(getItsLife()==0)
    {

        die();
    }

}

void IA::die()
{
    stop = true;
    setIsDead(true);
    itsTimeD=0;
    itsTimeG=0;
    setItsHeight(0);
    setItsWidth(0);
}

int IA::getGunY() const
{
    return itsHeight/3+itsY;
}

void IA::animate()
{
    itsTimeD++;
    itsTimeG++;
    // left
    if(switchMove == 1)
    {
        itsAnimationImage = 1;
    }
    //right
    if(switchMove == 2)
    {
        itsAnimationImage = 2;
    }
    if (switchMove == 0)
    {
        itsAnimationImage = 0;
    }
    if (forNoMove == true)
    {
        itsAnimationImage = 4;
    }

}

void IA::incrementCanShoot()
{
    if(itsTimerCanShoot > itsTimeMinShoot )
    {
        itsTimerCanShoot = 0;
    }
    else
    {
        itsTimerCanShoot++;
    }

}

bool IA::canShoot()
{
    return itsTimerCanShoot == 0;
}

bool IA::detectPlayer(Personnage* player)
{

    double distanceX = player->getItsX() - itsX;
    int distanceBlocY = player->getItsBlockY() - getItsBlockY();
    bool beReturn = distanceX < 400 && distanceX > -400 && distanceBlocY > -4 && distanceBlocY < 6;

        if(beReturn)
        {
            stop = true;
            setDirection(distanceX < 0);
            if(itsDirection)
            {
                switchMove = 2;
            }
            else
            {
                 switchMove = 1;
            }

        }
        else if(stop)
        {
            if(itsDirection)
            {
                switchMove = 1;
            }
            else
            {
                 switchMove = 2;
            }
            stop = false;
            itsTimeD = 0;
            itsTimeG = 0;

        }
    return beReturn;


}
