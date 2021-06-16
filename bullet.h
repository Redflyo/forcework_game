#ifndef BULLET_H
#define BULLET_H
#include "physicalobject.h"
#include "personnage.h"

class Bullet: public PhysicalObject
{
private:
    int itsSpeedX = 5;
    int itsSpeedY;
    int itsAnimationImage;
    Personnage *itsOwner;
    bool isHit = false;
    int animTime = 0;
public:
    ///
    /// \brief move deplace la balle en fonction de sa vitesse
    ///
    void move();
    ///
    /// \brief animate calcul d'animation de l'image (explosion)
    ///
    void animate();
    ///
    /// \brief Bullet Constructeur de la balle (Bullet)
    /// \param owner Proprietaire de la balle
    /// \param direction definie le sens que la balle (Bullet) va suivre
    ///
    Bullet(Personnage *owner, bool direction);
    ///
    /// \brief getItsOwner getter du proprietaire de la balle (Bullet)
    /// \return retourne un pointeur du propritetaire de la balle (Bullet)
    ///
    Personnage *getItsOwner() const;
    ///
    /// \brief getIsHit getter de itsHit
    /// \return si true la balle est entré en collision avec un objet
    ///
    bool getIsHit() const;
    ///
    /// \brief setIsHit setter de itsHit
    /// \param value définie si la balle à toucher un autre objet ou non
    ///
    void setIsHit(bool value);
    ///
    /// \brief getAnimTime getter de l'etat actuel de l'animation de l'explosion
    /// \return la valeur de animTime
    ///
    int getAnimTime() const;
    ///
    /// \brief setAnimTime setter de l'etat actuel de l'animation de l'explosion
    /// \param value la valeur de animTime
    ///
    void setAnimTime(int value);
    ///
    /// \brief setItsSpeedX setter de itsSpeedX
    /// \param value défini la vitesse horizontale de la balle (Bullet)
    ///
    void setItsSpeedX(int value);
    ///
    /// \brief getItsSpeedX getter de itsSpeedX
    /// \return retourne la vitesse Horizontale de la balle (Bullet)
    ///
    int getItsSpeedX() const;
};

#endif // BULLET_H
