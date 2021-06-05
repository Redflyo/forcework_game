#include "physicalobject.h"

int PhysicalObject::getItsBlockX() const
{
    return itsBlockX;
}

void PhysicalObject::setItsBlockX(int value)
{
    itsBlockX = value;
}

int PhysicalObject::getItsBlockY() const
{
    return itsBlockY;
}

void PhysicalObject::setItsBlockY(int value)
{
    itsBlockY = value;
}

int PhysicalObject::getItsY() const
{
    return itsY;
}

void PhysicalObject::setItsY(int value)
{
    itsY = value;
}

int PhysicalObject::getItsX() const
{
    return itsX;
}

void PhysicalObject::setItsX(int value)
{
    itsX = value;
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
