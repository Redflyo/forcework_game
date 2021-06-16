#include "physicalobject.h"
#include <QDebug>

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

int PhysicalObject::getItsWidth() const
{
  return itsWidth;
}

void PhysicalObject::setItsWidth(int value)
{
  itsWidth = value;
}

int PhysicalObject::getItsHeight() const
{
  return itsHeight;
}

void PhysicalObject::setItsHeight(int value)
{
  itsHeight = value;
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

int PhysicalObject::isCollide(PhysicalObject anObject1, PhysicalObject anObject2)
{
  int beReturn = 0;
  QRect rect1 = QRect(anObject1.getItsX(),anObject1.getItsY(),anObject1.getItsWidth(),anObject1.getItsHeight());
  QRect rect2 = QRect(anObject2.getItsX(),anObject2.getItsY(),anObject2.getItsWidth(),anObject2.getItsHeight());
  if(rect1.intersects(rect2))
  {
      return 1;
  }
  else
  {
      return 2;
  }

  /*
  if(y1<y4 && y1>y3)
  {
      if(y2<y4 && y2>y3)
      {
          if(x1<x4 && x1>x3)
          {
              if(x2<x4 && x2>x3)
              {
                  beReturn = 1;
              }
          }
      }
  }*/

  return beReturn;
}


