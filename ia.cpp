#include "ia.h"


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

IA::IA(int blockXBegin,int blockXEnd,int blockYRound, bool moveOrNot)
{
    roundBlockXBegin = blockXBegin;
    roundBlockXEnd = blockXEnd;
    roundBlockY = blockYRound;
    roundBlockXNow = roundBlockXBegin;
    itsX = blockToPixel(roundBlockXNow);
    itsY = blockToPixel(roundBlockY);
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



}

IA::~IA()
{

}

void IA::move(std::vector<Block> & itsMap)
{
    if (itsX<roundXBegin)
    {
        itsTurn = false;
        switchMove = 2;
    }
    if(itsX>roundXEnd)
    {
        itsTurn = true;
        switchMove = 1;

    }

    if (stop == false)
    {

        if (roundBlockXBegin != roundBlockXEnd)
        {
            // left
            if (itsTurn == true)
            {

                setItsX( itsX -2 );

            }

            //right
            if (itsTurn==false )
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

}

void IA::beShot()
{
    if(getItsY()-1==0)
    {
        die();
    }
    else
    {
        setItsLife(getItsY()-1);
    }
}

void IA::die()
{

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
