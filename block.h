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

    static QImage getQImage(int type);

};

#endif // BLOCK_H
