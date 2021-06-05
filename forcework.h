#ifndef FORCEWORK_H
#define FORCEWORK_H
#include <player.h>
#include <ia.h>
#include <vector>
#include <map.h>
#include <camera.h>
#include <QSet>
#include "settings.h"


using namespace std;
class ForceWork
{
private:


    QSet<int> pressedKeys;
    ///
    /// \brief personnages Le joueur est à l'index 0
    ///
    vector<Personnage*> itsPersonnages;
    Map itsMap;
    Camera camera;
    Settings *itsSettings;


public:
    ~ForceWork();
    ForceWork(Settings * settings);
    void gameLoop();
    void manageKeys();
    void addPersonnage(Personnage * personnage);
    void addPersonnage(Player player);
    void addPersonnage(IA ia);
    Player* getPlayer();

    Map getItsMap();

    Camera& getCamera();
    QSet<int>& getPressedKeys();
};

#endif // FORCEWORK_H
