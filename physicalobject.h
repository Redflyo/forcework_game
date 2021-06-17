#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include <QMainWindow>

static const int sizeBlock = 42;
static int pixelToBlock(int xOrY)
{

    return xOrY / sizeBlock;
}
static int blockToPixel(int xOrY)
{
    return xOrY * sizeBlock;
}

class PhysicalObject
{
protected:
    int itsBlockX, itsBlockY=0;
    int itsX=0;
    int itsY=0;
    int itsWidth=0;
    int itsHeight=0;
public:
    PhysicalObject();
    ~PhysicalObject();
    ///
    /// \brief isCollide
    /// \param anObject1
    /// \param anObject2
    /// \return
    static int isCollide(PhysicalObject anObject1, PhysicalObject anObject2);




    ///
    /// \brief getItsBlockX getter de itsBlockX
    /// \return retourne la position X (en block) de l'objet
    ///
    int getItsBlockX() const;
    ///
    /// \brief setItsBlockX définie itsBlockX ainsi que itsX
    /// \param value valeur de position x (en block) de l'objet
    ///
    void setItsBlockX(int value);

    ///
    /// \brief getItsBlockY getter de itsBlockY
    /// \return retourne la position Y (en block) de l'objet
    ///
    int getItsBlockY() const;

    ///
    /// \brief setItsBlockY définie itsBlockY ainsi que itsY
    /// \param value valeur de position y (en block) de l'objet
    ///
    void setItsBlockY(int value);
    /// \brief getItsY getter de itsY
    /// \return retourne la position Y (en pixel) de l'objet
    ///
    int getItsY() const;
    ///
    /// \brief setItsY définie itsBlockY ainsi que itsY
    /// \param value valeur de position y (en pixel) de l'objet
    ///
    void setItsY(int value);
    /// \brief getItsX getter de itsX
    /// \return retourne la position x (en pixel) de l'objet
    ///
    int getItsX() const;
    ///
    /// \brief setItsX définie itsBlockX ainsi que itsX
    /// \param value valeur de position x (en pixel) de l'objet
    ///
    void setItsX(int value);
    ///
    /// \brief getItsWidth permet d'obtenir la largeur de l'objet
    /// \return itsWidth soit la largeur en pixel de l'objet
    ///
    int getItsWidth() const;
    ///
    /// \brief setItsWidth defini la largeur de l'objet
    /// \param value valeur en pixel de la largeur de l'objet
    ///
    void setItsWidth(int value);
    ///
    /// \brief getItsHeight permet d'obtenir la hauteur de l'objet
    /// \return retourne la hauteur de l'objet en pixel
    ///
    int getItsHeight() const;
    ///
    /// \brief setItsHeight permet de definir la hauteur de l'objet
    /// \param value valeur en pixel de la futur hauteur de l'objet
    ///
    void setItsHeight(int value);
};

#endif // PHYSICALOBJECT_H
