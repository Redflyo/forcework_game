#ifndef BLOCK_H
#define BLOCK_H
#include "physicalobject.h"
#include "QImage"
class Block: public PhysicalObject
{
private:
    int itsBlockType;
public:
    ///
    /// \brief Block Constructeur du block
    /// \param type type de block qui lui sera attribue
    ///
    Block(int type);
    ///
    /// \brief Block Constructeur du block
    /// \param type type de block qui lui sera attribue
    /// \param blockX defini la position X du block (en Block)
    /// \param blockY defini la position Y du block (en Block)
    ///
    Block(int type,int blockX,int blockY);

    ///
    /// \brief getItsBlockType getter de itsBlockType
    /// \return retourne le type du block
    ///
    int getItsBlockType() const;
    ///
    /// \brief setItsBlockType setter de itsBlockType
    /// \param value défini le type du block
    ///
    void setItsBlockType(int value);
};

#endif // BLOCK_H
