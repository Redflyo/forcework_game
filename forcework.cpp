#include "forcework.h"




Map ForceWork::getItsMap()
{
    return itsMap;
}

Camera& ForceWork::getCamera()
{
    return *camera;
}

QSet<int>& ForceWork::getPressedKeys()
{
    return pressedKeys;
}

QString ForceWork::getTickScore() const
{
    QString Score;
    int cent =tickScore%100;
    int second = tickScore/100;
    int min = second/60;
    second -= min*60;
    if(min==0)
    {
        Score = QString::number(second) + ":" + QString::number(cent);
    }
    else Score = QString::number(min) + ":" + QString::number(second) + ":" + QString::number(cent);
    return Score;
}

Settings *ForceWork::getItsSettings() const
{
    return itsSettings;
}

vector<Bullet *> ForceWork::getItsBullets() const
{
    return itsBullets;
}

ForceWork::~ForceWork()
{

    for(Personnage* perso: itsPersonnages)
    {
        delete perso;
    }

}

ForceWork::ForceWork(Settings * settings)
{
    itsSettings = settings;
    Map map;
    itsMap = map;
    itsPersonnages = itsMap.loadMap("../forcework_game/data/mapTest.txt");
    camera = new Camera(itsMap.getItsWidthMap(),itsMap.getItsHeightMap());


}

void ForceWork::gameLoop()
{
    manageKeys();
    Player* aPlayer = getPlayer();
    aPlayer->move(itsMap.getItsBlocks());
    aPlayer->animate();
    getCamera().follow((PhysicalObject)(*aPlayer));
    tickScore++;
    for(vector<Bullet*>::iterator it = itsBullets.begin(); it!=itsBullets.end(); it++)
    {
        (*it)->move();
    }

}

void ForceWork::manageKeys()
{
    if(pressedKeys.size() ==0)
    {
        getPlayer()->setMovement(0);
    }
    else
    {
        for(int key : pressedKeys)
        {
            if(itsSettings->validJump(key))
            {
                getPlayer()->jump();
            }
            if(itsSettings->validRight(key))
            {
                getPlayer()->setMovement(2);
                getPlayer()->setDirection(false);
            }
            if(itsSettings->validLeft(key))
            {
                getPlayer()->setMovement(1);
                getPlayer()->setDirection(true);
            }

        }
    }

}

void ForceWork::addPersonnage(Personnage *personnage)
{
    itsPersonnages.push_back(personnage);
}

void ForceWork::addPersonnage(Player player)
{
    addPersonnage(&player);
}

void ForceWork::addPersonnage(IA ia)
{
    addPersonnage(&ia);
}

Player *ForceWork::getPlayer()
{
    return (Player*)itsPersonnages[0];
}

void ForceWork::addBullet(Bullet *a)
{
    itsBullets.emplace_back(a);
}

void ForceWork::deleteBullet(Bullet *a)
{
    for(vector<Bullet*>::iterator it = itsBullets.begin(); it!=itsBullets.end(); it++)
    {
        if(*it == a) itsBullets.erase(it);
    }
}
