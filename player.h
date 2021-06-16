#ifndef PLAYER_H
#define PLAYER_H
#include "personnage.h"
#include "map.h"
#include <vector>

class Player: public Personnage
{
public:
    Player();
    virtual ~Player();
    virtual void move(std::vector<Block> itsMap);
    virtual void shoot();
    virtual void beShot();
    virtual void die();
    virtual void animate();
    bool isWin();
};



#endif // PLAYER_H
