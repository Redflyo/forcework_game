#ifndef CAMERA_H
#define CAMERA_H


class Camera
{
private:
    int itsOffsetX;
    int itsOffsetY;
    bool itsFollowing;
public:
    Camera();
    void foolow();
};

#endif // CAMERA_H
