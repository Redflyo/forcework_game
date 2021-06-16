#ifndef IA_H
#define IA_H
#include "personnage.h"
#include "block.h"

class IA : public Personnage
{
private:
    bool itsOrientation;

    int roundXBegin,roundYEnd;
    int roundY;

    int roundBlockY;
    int roundBlockXBegin,roundBlockYEnd;
public:
    IA(int blockXBegin,int blockXEnd,int blockYRound);
    virtual ~IA();
    virtual void move(std::vector<Block> itsMap);
    virtual void shoot();
    virtual void beShot();
    virtual void die();
    virtual void animate();
};



#endif // IA_H
