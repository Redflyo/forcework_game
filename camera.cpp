#include "camera.h"

int Camera::getItsOffsetX()
{
    return itsOffsetX;
}

int Camera::getItsOffsetY() const
{
    return itsOffsetY;
}
Camera::Camera(int widthBlockMap,int heightBlockMap)

{
    itsWidthBlockMap = widthBlockMap;
    itsHeightBlockMap = heightBlockMap;
    itsOffsetX = 0;
    itsOffsetY = 0;
}

void Camera::follow(PhysicalObject object)
{

    itsOffsetX = -(object.getItsX() -500);
    itsOffsetY = -(object.getItsY()-200);
    if(-itsOffsetX < 0)
    {
        itsOffsetX =0;
    }
    else if(1200 >= itsWidthBlockMap*sizeBlock+itsOffsetX )
    {
        itsOffsetX = -(sizeBlock*itsWidthBlockMap) + 1200;
    }
    if(-itsOffsetY < 0)
    {
        itsOffsetY =0;
    }
    else if(399 >= itsHeightBlockMap*sizeBlock+itsOffsetY )
    {
        itsOffsetY = -(sizeBlock*itsHeightBlockMap) + 399;
    }

}
