#ifndef CAMERA_H
#define CAMERA_H
#include "physicalobject.h"

class Camera
{
private:
    int itsOffsetX=0;
    int itsOffsetY=0;
    int itsWidthBlockMap,itsHeightBlockMap=21;
public:
    ///
    /// \brief Camera constructeur de Camera
    /// \param widthBlockMap obtiens la taille de la carte en block
    /// \param sizeBlock définie la taille d'un bloc
    ///
    Camera(int widthBlockMap,int heightBlockMap);
    ///
    /// \brief follow La camera traque un objet dans les limites de la carte (surtout le joueur)
    /// \param object objet qui va etre tracke
    ///
    void follow(PhysicalObject object);

    ///
    /// \brief getItsOffsetX getter du decalage de la camera sur les X
    /// \return retourne le decalage de la camera en X
    ///
    int getItsOffsetX();
    ///
    /// \brief getItsOffsetY getetr du decalage de la camera sur les Y
    /// \return retourne le decalage de la camera en Y
    ///
    int getItsOffsetY() const;
};

#endif // CAMERA_H
