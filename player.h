#ifndef PLAYER_H
#define PLAYER_H
#include "personnage.h"

class Player: public Personnage
{
public:
    Player();
    virtual void move(int anMovement);
    virtual void shoot();
    virtual void beShot();
    virtual void die();
    virtual void animate();
    void checkMove(int anMovement);
};

#endif // PLAYER_H
