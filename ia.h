#ifndef IA_H
#define IA_H
#include "personnage.h"

class IA : public Personnage
{
private:
    bool itsOrientation;
    int roundXBegin,roundYEnd;
    int roundY;
public:
    IA();
    virtual void move(int anMovement);
    virtual void shoot();
    virtual void beShot();
    virtual void die();
    virtual void animate();
};



#endif // IA_H
