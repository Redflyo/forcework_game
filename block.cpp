#include "block.h"

int Block::getItsBlockType() const
{
    return itsBlockType;
}

void Block::setItsBlockType(int value)
{
    itsBlockType = value;
}

Block::Block(int type)
{
    this->itsBlockType = type;
}

Block::Block(int type, int blockX, int blockY)
{
    this->itsBlockType = type;
    this->itsBlockX = blockX;
    this->itsBlockY = blockY;
}
