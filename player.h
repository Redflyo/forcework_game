#ifndef PLAYER_H
#define PLAYER_H
#include "personnage.h"
#include "map.h"
#include <vector>

class Player: public Personnage
{
private:
    int itsTimeOfJump = 0;
    bool itsImpulsion = false; // true monte false descend
    bool itsGround=true; // true au sol false en l'air
    float itsPowerImpulsion = 0.4;
    const float gravity = 0.2;
public:
    Player();

    void resetJump();
    void jump();
    virtual ~Player();
    void move(std::vector<Block> & itsMap);
    virtual void shoot();
    virtual void beShot();
    virtual void die();
    virtual void animate();
    virtual int getGunY() const;
    bool getItsImpulsion() const;
    bool getItsGround() const;
};



#endif // PLAYER_H
