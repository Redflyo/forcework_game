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
    IA(int blockXBegin,int blockXEnd,int blockYRound);
    virtual ~IA();
    virtual void move(std::vector<Block> & itsMap);
    virtual void shoot();
    virtual void beShot();
    virtual void die();
    virtual int getGunY() const;
    virtual void animate();
    void incrementCanShoot();
    bool canShoot();
    bool detectPlayer(Personnage * player);
    int getRoundBlockY() const;
    int getRoundBlockXBegin() const;
    int getRoundBlockXEnd() const;
    int getRoundBlockXNow() const;
    bool getItsMoveOrNot() const;
    int getItsTimeD() const;
    void setItsTimeD(int value);
    int getItsTimeG() const;
    void setItsTimeG(int value);
    int getSwitchMove() const;
};



#endif // IA_H
