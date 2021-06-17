#ifndef IA_H
#define IA_H
#include "personnage.h"
#include "block.h"

class IA : public Personnage
{
private:
    bool itsMoveOrNot; // savoir si c'est une ia qui bouge ou non true move false ne move pas
    int switchMove = 0;
    bool stop = false;
    bool forNoMove = false;
    bool animationDead = false;

    int roundXBegin,roundXEnd;
    int roundY;

    int roundBlockXNow;

    int roundBlockY;
    int roundBlockXBegin,roundBlockXEnd;
    int itsTimeD = 0;
    int itsTimeG = 0;
    int itsTimerCanShoot = 0;
    const int itsTimeMinShoot = 80;
public:
    ///
    /// \brief IA constructeur de IA
    /// \param blockXBegin position en X au debut de la ronde de l'IA
    /// \param blockXEnd position en X a la fin de la ronde de l'IA
    /// \param blockYRound position en Y de la ronde de l'IA
    ///
    IA(int blockXBegin,int blockXEnd,int blockYRound);
    ///
    /// \brief ~IA destructeur de l'IA
    ///
    virtual ~IA();
    ///
    /// \brief move deplace l'IA en suivant la ronde
    /// \param itsMap non utile pour l'IA mais structure imposé par heritage
    ///
    virtual void move(std::vector<Block> & itsMap);
    ///
    /// \brief beShot retire des vies à l'IA
    ///
    virtual void beShot();
    ///
    /// \brief die active l'animation de mort de l'IA et retire la collision du corps avec les balles
    ///
    virtual void die();
    ///
    /// \brief getGunY retourne la position y du canon de l'IA
    /// \return retourne la position y du canon de IA en pixel
    ///
    virtual int getGunY() const;
    ///
    /// \brief animate change l'animation en fonction de l'orientation de l'IA
    ///
    virtual void animate();
    ///
    /// \brief shoot defini que le joueur a tirer et qu'il va devoir attendre un certain delais
    ///
    void shoot();
    ///
    /// \brief incrementCanShoot increment le timer qui empeche l'IA de tirer
    ///
    void incrementCanShoot();
    ///
    /// \brief canShoot vérifie si l'IA peut tirer
    /// \return retourne true si l'IA peut tirer
    ///
    bool canShoot();
    ///
    /// \brief detectPlayer si l'ia detecte le joueur elle s'arrête et s'oriente dans son sens
    /// \param player Joueur afin de tenter de le detecter
    /// \return retourne true si le joueur est detecter par l'ia
    ///
    bool detectPlayer(Personnage * player);
    ////
    /// \brief getRoundBlockY getter de la position y en bloc
    /// \return retourne la position y de la ronde
    ///
    int getRoundBlockY() const;
    ///
    /// \brief getRoundBlockXBegin getter de la position X du debut de la ronde
    /// \return retourne la position x du debut de la ronde
    ///
    int getRoundBlockXBegin() const;
    ///
    /// \brief getRoundBlockXEnd getter de la position X de la fin de la ronde
    /// \return  retourne  la position x de la fin de la ronde
    ///
    int getRoundBlockXEnd() const;
    ///
    /// \brief getRoundBlockXNow getter de la position X acutel de l'ia en block
    /// \return retourne la position X actuel en block de l'ia
    ///
    int getRoundBlockXNow() const;
    ///
    /// \brief getItsMoveOrNot getter de itsMoveOrNot
    /// \return retourne true si l'ia fait des rondes et retourne false si l'ia est statique
    ///
    bool getItsMoveOrNot() const;
    ///
    /// \brief getItsTimeD getter de itsTimeD
    /// \return retourne l'etat de l'animation quand l'ia s'oriente vers la droite
    ///
    int getItsTimeD() const;
    ///
    /// \brief setItsTimeD setter de itsTimeD
    /// \param value defini le timer de l'animation vers la droite
    ///
    void setItsTimeD(int value);
    ///
    /// \brief getItsTimeG setter de itsTimeG
    /// \return retourne l'etat de l'animation quand l'ia s'oriente vers la gauche
    ///
    int getItsTimeG() const;
    ///
    /// \brief setItsTimeG setter de itsTimeG
    /// \param value defini le timer de l'animation vers la gauche
    ///
    void setItsTimeG(int value);
    ///
    /// \brief getSwitchMove getter de switchMove
    /// \return variable propre afin de gérer les transitions, des rondes
    ///
    int getSwitchMove() const;
    ///
    /// \brief setAnimationDead setter qui permet de definir si l'ia doit realiser l'animation de mort
    /// \param value true si l'ia doit realiser l'animation de mort et false sinon
    ///
    void setAnimationDead(bool value);
    ///
    /// \brief getAnimationDead getter permettant de savoir si l'animation de mort à commencé
    /// \return true si l'ia est entrain de realiser l'animation de mort et false sinon
    ///
    bool getAnimationDead() const;
};



#endif // IA_H
