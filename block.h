#ifndef BLOCK_H
#define BLOCK_H
#include "physicalobject.h"
#include "QImage"
class Block: public PhysicalObject
{
private:
    int itsBlockType;
public:
    Block(int type);
    Block(int type,int blockX,int blockY);

    static QImage getQImage(int type);

    int getItsBlockType() const;
    void setItsBlockType(int value);
};

#endif // BLOCK_H
