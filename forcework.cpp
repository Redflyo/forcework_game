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
    camera = new Camera(itsMap.getItsWidthMap(),21);


}

void ForceWork::gameLoop()
{
    manageKeys();
    getPlayer()->move();
    getCamera().follow((PhysicalObject)(*getPlayer()));



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
            if(itsSettings->validRight(key))
            {
                getPlayer()->setMovement(2);
            }
            if(itsSettings->validLeft(key))
            {
                getPlayer()->setMovement(1);
            }
            if(itsSettings->validJump(key))
            {

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
