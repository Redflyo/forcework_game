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

int PhysicalObject::isCollideH(PhysicalObject anObject1, PhysicalObject anObject2)
{
  int x1 = anObject1.getItsX(),
      x2 = anObject1.getItsX()+anObject1.getItsWidth(),
      x3 = anObject2.getItsX(),
      x4 = anObject2.getItsX()+anObject1.getItsWidth();

  qDebug() << x1 << " " << x2 << " " << x3 << " " << x4;

  if(x1>x4 && x1<x3) return 1;
  else if(x2>x4 && x2<x3) return 2;
  else return 0;
}

int PhysicalObject::isCollideV(PhysicalObject anObject1, PhysicalObject anObject2)
{
  int y1 = anObject1.getItsY(),
      y2 = anObject1.getItsY()+anObject1.getItsHeight(),
      y3 = anObject2.getItsY(),
      y4 = anObject2.getItsY()+anObject1.getItsHeight();
  if(y1>y4 && y1<y3) return 1;
  else if(y2>y4 && y2<y3) return 2;
  else return 0;
}
