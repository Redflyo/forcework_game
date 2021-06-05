#ifndef CAMERA_H
#define CAMERA_H
#include "physicalobject.h"

class Camera
{
private:
    int itsOffsetX;
    int itsOffsetY;
    int itsWidthBlockMap;
    int itsSizeBlock;
public:
    ///
    /// \brief Camera constructeur de Camera
    /// \param widthBlockMap obtiens la taille de la carte en block
    /// \param sizeBlock définie la taille d'un bloc
    ///
    Camera(int widthBlockMap, int sizeBlock);
    void follow(PhysicalObject object);


    int getItsOffsetX();
    int getItsOffsetY() const;
};

#endif // CAMERA_H
