#ifndef CAMERA_H
#define CAMERA_H
#include "physicalobject.h"

class Camera
{
private:
    int itsOffsetX;
    int itsOffsetY;
    bool itsFollowing;
public:
    Camera();
    void follow(PhysicalObject object);


    int getItsOffsetX();
    int getItsOffsetY() const;
};

#endif // CAMERA_H
