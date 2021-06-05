#include "camera.h"

int Camera::getItsOffsetX()
{
    return itsOffsetX;
}

int Camera::getItsOffsetY() const
{
    return itsOffsetY;
}

Camera::Camera()
{
    itsOffsetX = 0;
    itsOffsetY = 0;
}

void Camera::follow(PhysicalObject object)
{
    itsOffsetX = object.getItsX() -200;
}
