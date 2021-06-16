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
    int tickScore = 0;


public:

    ~ForceWork();
    ForceWork(Settings * settings);
    void gameLoop();
    void manageKeys();
    void addPersonnage(Personnage * personnage);
    void addPersonnage(Player player);
    void addPersonnage(IA ia);
    Player* getPlayer();
    void addBullet(Bullet *a);
    void deleteBullet(Bullet *a);
    Map getItsMap();

    Camera& getCamera();
    QSet<int>& getPressedKeys();
    QString getTickScore() const;
    Settings *getItsSettings() const;
    vector<Bullet *> getItsBullets() const;

    vector<Personnage *> getItsPersonnages() const;
};

#endif // FORCEWORK_H
