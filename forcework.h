#ifndef FORCEWORK_H
#define FORCEWORK_H
#include <player.h>
#include <ia.h>
#include <vector>
#include <map.h>
#include <camera.h>
#include <QSet>
#include "bullet.h"
#include "settings.h"

using namespace std;
class ForceWork
{
private:


    QSet<int> pressedKeys;
    ///
    /// \brief personnages Le joueur est Ã  l'index 0
    ///
    vector<Personnage*> itsPersonnages;
    vector<Bullet*> itsBullets;
    Map itsMap;
    Camera * camera;
    Settings *itsSettings;
    bool haveWin = false;
    int tickScore = 0;


public:
    ~ForceWork();
    ///
    /// \brief ForceWork constructeur de la partie
    /// \param settings settings defini (notamment les touches de mouvement)
    ///
    ForceWork(Settings * settings);
    ///
    /// \brief playerHaveWin verifie si le joueur a atteind le drapeau
    ///
    void playerHaveWin();
    ///
    /// \brief gameLoop methode gerant le deroulement de la partie
    ///
    void gameLoop();
    ///
    /// \brief manageKeys gere la gestion des touches
    ///
    void manageKeys();
    ///
    /// \brief addPersonnage ajoute un personnage a itsPersonnages
    /// \param personnage personnage a ajouter
    ///
    void addPersonnage(Personnage * personnage);
    ///
    /// \brief addPersonnage ajoute un personnage a itsPersonnages
    /// \param player personnage a ajouter
    ///
    void addPersonnage(Player player);
    ///
    /// \brief addPersonnage ajoute un personnage a itsPersonnages
    /// \param ia ajoute une ia
    ///
    void addPersonnage(IA ia);
    ///
    /// \brief getPlayer retourne le personnage avec l'index 0 du table itsPersonnages soit le joueur
    /// \return le pointeur du joueur
    ///
    Player* getPlayer();
    ///
    /// \brief addBullet ajoute a itsBullets une nouvelle balle
    /// \param a correspond a la balle a ajouter
    ///
    void addBullet(Bullet *a);
    ///
    /// \brief getItsMap getter de l'objet Map
    /// \return retourne l'objet Map
    ///
    Map getItsMap();
    ///
    /// \brief getCamera getter de la camera
    /// \return la camera par reference
    ///
    Camera& getCamera();
    ///
    /// \brief getPressedKeys ensemble des touches pressees par le joueur
    /// \return l'ensemble des touches pressees par le joueur
    ///
    QSet<int>& getPressedKeys();
    ///
    /// \brief getTickScore getter du score du joueur
    /// \return le score du joueur
    ///
    QString getTickScore() const;
    ///
    /// \brief getItsSettings getter des settings
    /// \return retourne les settings
    ///
    Settings *getItsSettings() const;
    ///
    /// \brief moveBulletGameloop realise le mouvement balles tiree
    ///
    void moveBulletGameloop();
    ///
    /// \brief bulletsCheckCollision gestion des collisions des balles tirees
    ///
    void bulletsCheckCollision();
    ///
    /// \brief getItsBullets getter de l'ensemble des balles tirees
    /// \return retourne l'ensemble bullets tiree encore active
    ///
    vector<Bullet *> getItsBullets() const;
    ///
    /// \brief getItsPersonnages getter de la liste des personnages (IA et Player)
    /// \return retourne les personnages par pointeurs    ///

    vector<Personnage *> getItsPersonnages() const;
    ///
    /// \brief animateBullets realise l'animation des balles
    ///
    void animateBullets();
    ///
    /// \brief iaGameLoop Boucle afin de gerer le comportement des IA
    ///
    void iaGameLoop();
    ///
    /// \brief getHaveWin getter permettant de savori si la partie est gagne
    /// \return retourne true si la partie est gagne par le joueur
    ///
    bool getHaveWin() const;
};

#endif // FORCEWORK_H
