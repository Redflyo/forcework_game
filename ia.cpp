#include "ia.h"


IA::IA(int blockXBegin,int blockXEnd,int blockYRound)
{

}

IA::~IA()
{

}

void IA::move(std::vector<Block> & itsMap)
{

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

}
