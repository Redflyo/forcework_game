#ifndef PLAYER_H
#define PLAYER_H
#include "personnage.h"
#include "map.h"
#include <vector>

class Player: public Personnage
{
private:
    int itsTimeOfJump = 0;
    bool itsImpulsion = false; // true monte false descend
    bool itsGround=true; // true au sol false en l'air
    float itsPowerImpulsion = 0.4;
    const float gravity = 0.2;
public:
    Player();

    ///
    /// \brief resetJump Renitialise le saut du joueur afin que il puisse de nouveau sauter
    ///
    void resetJump();
    ///
    /// \brief jump Initialise le saut du joueur
    ///
    void jump();
    ///
    /// \brief ~Player Detruit proprement l'objet Player
    ///
    virtual ~Player();
    ///
    /// \brief move Deplace le joueur en prennant en compte les contraintes de collision
    /// \param itsMap passe en parametre de la methode la map afin de detecter les collisions
    ///
    void move(std::vector<Block> & itsMap);
    ///
    /// \brief beShot diminue la vie du joueur et potentiellement declenche la mort du personnage
    ///
    virtual void beShot();
    ///
    /// \brief die Methode symbolisant la mort du joueur
    ///
    virtual void die();
    ///
    /// \brief animate En fonction du deplacement du joueur adaptera son animation
    ///
    virtual void animate();
    ///
    /// \brief getGunY symbolise la hauteur du canon du joueur
    /// \return retourne la position y du départ des balles
    ///
    virtual int getGunY() const;
    ///
    /// \brief getItsImpulsion getter sur la variable itsImpulsion
    /// \return retourne true si le joueur reçoit l'acceleration de son saut
    ///
    bool getItsImpulsion() const;
    ///
    /// \brief getItsGround getter sur la variable itsGround
    /// \return retourne true
    ///
    bool getItsGround() const;
};



#endif // PLAYER_H
