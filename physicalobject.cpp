#include "physicalobject.h"

int PhysicalObject::getItsBlockX() const
{
    return itsBlockX;
}

void PhysicalObject::setItsBlockX(int value)
{
    itsBlockX = value;
    itsX = blockToPixel(itsBlockX);
}

int PhysicalObject::getItsBlockY() const
{
    return itsBlockY;
}

void PhysicalObject::setItsBlockY(int value)
{
    itsBlockY = value;
    itsY = blockToPixel(itsBlockY);
}

int PhysicalObject::getItsY() const
{
    return itsY;
}

void PhysicalObject::setItsY(int value)
{
    itsY = value;
    itsBlockY = pixelToBlock(itsY);
}

int PhysicalObject::getItsX() const
{
    return itsX;
}

void PhysicalObject::setItsX(int value)
{
    itsX = value;
    itsBlockX = pixelToBlock(itsX);
}

PhysicalObject::PhysicalObject()
{
    itsBlockX =0;
    itsBlockY = 0;
    itsX =0;
    itsY = 0;
    itsHeight = 0;
    itsWidth = 0;
}

PhysicalObject::~PhysicalObject()
{

}
