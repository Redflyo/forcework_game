#include "camera.h"

int Camera::getItsOffsetX()
{
    return itsOffsetX;
}

int Camera::getItsOffsetY() const
{
    return itsOffsetY;
}

Camera::Camera(int widthBlockMap,int sizeBlock)
{
    itsWidthBlockMap = widthBlockMap;
    itsSizeBlock = sizeBlock;
    itsOffsetX = 0;
    itsOffsetY = 0;
}

void Camera::follow(PhysicalObject object)
{

    itsOffsetX = -(object.getItsX() -500);
    if(itsOffsetX*-1 < 0)
    {
        itsOffsetX =0;
    }
    else if(1200 >= itsWidthBlockMap*itsSizeBlock+itsOffsetX )
    {
        itsOffsetX = -(itsSizeBlock*itsWidthBlockMap) + 1200;
    }
}
