#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "physicalobject.h"
#include "block.h"

class Personnage: public PhysicalObject
{
protected:
    int itsLife;
    int itsAnimationImage = 0;
    bool itsGround;
    //bool itsTurn = false; // false pour droite et true pour gauche
    float itsSpeedY=0;
    int itsMovement;
    int itsSpeedX = 2;
    bool itsDirection = false;
    int gunY;
    bool isDead = false;
public:
    ///
    /// \brief Personnage Constructeur de l'objet Personnage (impossible l'objet est abstrait)
    ///
    Personnage();
    ///
    /// \brief ~Personnage Destructeur de l'objet Personnage
    ///
    virtual ~Personnage();
    ///
    /// \brief move patron de la fonction de déplacement des classes "enfants"
    /// \param itsMap correspond à la liste des blocs, utile pour Player afin de gerer les collisions
    ///
    virtual void move(std::vector<Block> & itsMap) = 0;
    ///
    /// \brief setMovement permet de definir le mouvement d'un personnage
    /// \param movement mouvement qui va etre appliquer au personnage (0 correspond a aucun mouvement,1 pour la gauche,2 pour la droite)
    ///
    virtual void setMovement(int movement);
    ///
    /// \brief beShot patron de la methode de collision avec une balle des classes "enfants"
    ///
    virtual void beShot() = 0;
    ///
    /// \brief die patron de la methode de mort des classes "enfants"
    ///
    virtual void die() = 0;
    ///
    /// \brief animate patron de la fonction d'animation des classes "enfants"
    ///
    virtual void animate() = 0;
    ///
    /// \brief getItsAnimationImage getter de itsAnimationImage
    /// \return retourne sur quelles images c'est arretes l'animation
    ///
    int getItsAnimationImage() const;
    ///
    /// \brief getGunY patron de la fonction qui indique la position y du canon des classes "enfants"
    /// \return retourne le y correspond à la hauteur du canon du personnage
    ///
    virtual int getGunY() const = 0;

    ///
    /// \brief getItsSpeedY getter de la vitesse y du personnage
    /// \return la vitesse y du personnage
    ///
    float getItsSpeedY() const;
    ///
    /// \brief getDirection getter de itsDirect soit l'orientation du personnage
    /// \return retourne true si le personnage regarde vers la gauche et false pour la droite
    ///
    bool getDirection() const;
    ///
    /// \brief setDirection setter de itsDirection
    /// \param value défini une orientation du personnage
    ///
    void setDirection(bool value);
    ///
    /// \brief getItsLife getter de itsLife soit le nombre de vie restante avant de mourir
    /// \return retourne le nombre de vie restante
    ///
    int getItsLife() const;
    ///
    /// \brief setItsLife définie le nombre de vie restantes du personnage
    /// \param value nombre de vie qui restera au personnage
    ///
    void setItsLife(int value);
    ///
    /// \brief getIsDead getter de itsDead soit si le personnage est mort
    /// \return retourne true si le personnage est mort et false si il est en vie
    ///
    bool getIsDead() const;
    ///
    /// \brief setIsDead setter de itsDead
    /// \param value defini si le personage est en vie ou mort
    ///
    void setIsDead(bool value);
};

#endif // PERSONNAGE_H
