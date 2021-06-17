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
    QString Qsecond = QString::number(second);
    QString Qcent = QString::number(cent);
    QString Qmin = QString::number(min);
    if(min==0)
    {
        Qmin = "00";
    }
    if(min<10)
    {
        Qmin = "0" + QString::number(min);
    }
    if(second==0)
    {
        Qsecond = "00";
    }
    if(second<10)
    {
        Qsecond = "0" + QString::number(second);
    }
    if(cent==0)
    {
        Qcent = "00";
    }
    if(cent<10)
    {
        Qcent = "0" + QString::number(cent);
    }
    Score = Qmin + ":" + Qsecond + ":" + Qcent;
    return Score;
}

Settings *ForceWork::getItsSettings() const
{
    return itsSettings;
}

void ForceWork::moveBulletGameloop()
{
    for(vector<Bullet*>::iterator it = itsBullets.begin(); it!=itsBullets.end();)
    {
        (*it)->move();
        if((*it)->getIsHit() && (*it)->getAnimTime() > 60)
        {
            delete *it;
            itsBullets.erase(it);
        }
        if(it != itsBullets.end()) it++;
    }
}

void ForceWork::bulletsCheckCollision()
{

    for(Block bloc: itsMap.getItsBlocks())
    {
        if(!(bloc.getItsBlockType()==0 || bloc.getItsBlockType()==1))
        {
            for(vector<Bullet*>::iterator it = itsBullets.begin(); it!=itsBullets.end();)
            {
                 if((*it)->isCollide((*(*it)), bloc)==1)
                 {
                     (*it)->setIsHit(true);
                     (*it)->setItsSpeedX(0);
                 }
                 if(it != itsBullets.end()) it++;
            }
        }
    }
    for(Personnage *person: itsPersonnages)
    {
            for(vector<Bullet*>::iterator it = itsBullets.begin(); it!=itsBullets.end();)
            {
                 if((*it)->isCollide((*(*it)), *person)==1 && (*it)->getItsSpeedX()!=0)
                 {
                     (*it)->setIsHit(true);
                     (*it)->setItsSpeedX(0);
                     person->beShot();
                     delete *it;
                     itsBullets.erase(it);


                 }
                 if(it != itsBullets.end()) it++;
            }
        }
}

vector<Bullet *> ForceWork::getItsBullets() const
{
    return itsBullets;
}

vector<Personnage *> ForceWork::getItsPersonnages() const
{
    return itsPersonnages;
}
void ForceWork::animateBullets()
{
    for(vector<Bullet*>::iterator it = itsBullets.begin(); it!=itsBullets.end();)
    {
        (*it)->animate();
        if((*it)->getAnimTime()>100)
        {
            Bullet * bull = *it;
            itsBullets.erase(it);
            delete bull;
        }
        if(it != itsBullets.end()) it++;
    }
}

void ForceWork::iaGameLoop()
{
    // ne prend pas le joueur
    for (int i = 1;i < (int)itsPersonnages.size();i++)
    {
        IA* ia = (IA*)itsPersonnages[i];
        if(!ia->getIsDead())
        {
            if(ia->detectPlayer(getPlayer()))
            {
                if(ia->canShoot())
                {
                    ia->shoot();
                    Bullet *bull = new Bullet(itsPersonnages[i], itsPersonnages[i]->getDirection());
                    addBullet(bull);

                }
                else
                {
                    ia->incrementCanShoot();
                }

             }
        }



        ia->move(itsMap.getItsBlocks());
        ia->animate();

    }
}

bool ForceWork::getHaveWin() const
{
    return haveWin;
}

QString ForceWork::noteIntro()
{
    if (getPlayer()->getItsBlockX() >= 0 and getPlayer()->getItsBlockX() <= 20)
    {
        QString premier;
        premier = "Vous pouvez avancer vers la droite en utilisant la flèche directionel droite ( → ) ou bien votre touche defini !";
        return premier;
    }
    else if (getPlayer()->getItsBlockX() >= 30 and getPlayer()->getItsBlockX() <= 40)
    {
        QString premier;
        premier = "Vous pouvez sauter en utilisant la flèche directionel haut ( ↑ ) ou bien votre touche defini !";
        return premier;
    }
    else if (getPlayer()->getItsBlockX() >= 44 and getPlayer()->getItsBlockX() <= 51 and getPlayer()->getItsBlockY() >= 10)
    {
        QString premier;
        premier = "Vous pouvez avancer vers la gauche en utilisant la flèche directionel gauche ( ← ) ou bien votre touche defini !";
        return premier;
    }
    else if (getPlayer()->getItsBlockX() >= 48 and getPlayer()->getItsBlockX() <= 53 and getPlayer()->getItsBlockY() <= 6)
    {
        QString premier;
        premier = "Vous pouvez abattre votre enemie en tirant avec le clique gauche de la souris";
        return premier;
    }
    else if (getPlayer()->getItsBlockX() >= 74 and getPlayer()->getItsBlockX() <= 94 and getPlayer()->getItsBlockY() <= 12)
    {
        QString premier;
        premier = "Attention ! les enemies peuvent bouger et tirer ! Esquive ses balles et tue le !";
        return premier;
    }
    else if (getPlayer()->getItsBlockX() >= 74 and getPlayer()->getItsBlockX() <= 94 and getPlayer()->getItsBlockY() <= 16 )
    {
        QString premier;
        premier = "Ils sont en prison, approche toi de la cellule pour qu'ils s'entretue";
        return premier;
    }
    else if (getPlayer()->getItsBlockX() >= 102 and getPlayer()->getItsBlockX() <= 116)
    {
        QString premier;
        premier = "Il faut maintenant atteindre le drapeau ! Dépêche-toi de le trouver !";
        return premier;
    }
    else
    {
        QString premier;
        premier = "ERROR";
        return premier;
    }
}

ForceWork::~ForceWork()
{
    delete  camera;
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
    if(itsSettings->getItsTutorial())
    {
        itsPersonnages = itsMap.loadMap("../forcework_game/data/mapIntro.txt");
    }
    else itsPersonnages = itsMap.loadMap("../forcework_game/data/mapTest.txt");
    camera = new Camera(itsMap.getItsWidthMap(),itsMap.getItsHeightMap());
}

void ForceWork::playerHaveWin()
{

    if(itsMap.getItsBlocks()[itsMap.getItsBlocks().size()-1].getItsBlockType() == 1 )
    {
        if(getPlayer()->isCollide(*getPlayer(),itsMap.getItsBlocks()[itsMap.getItsBlocks().size()-1]) == 1)
        {
            haveWin = true;
        }

    }

}

void ForceWork::gameLoop()
{
    manageKeys();
    Player* aPlayer = getPlayer();
    aPlayer->move(itsMap.getItsBlocks());
    aPlayer->animate();
    getCamera().follow((PhysicalObject)(*aPlayer));
    tickScore++;
    moveBulletGameloop();
    bulletsCheckCollision();

    playerHaveWin();
    animateBullets();

    iaGameLoop();

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
