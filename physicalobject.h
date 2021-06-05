#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include <QMainWindow>

class PhysicalObject
{
protected:
    int itsBlockX, itsBlockY=0;
    int itsX=0;
    int itsY=0;
    int itsWidth=0;
    int itsHeight=0;
public:
    PhysicalObject();
    ~PhysicalObject();
    ///
    /// \brief isCollide
    /// \param anObject1
    /// \param anObject2
    /// \return
    static int isCollide(PhysicalObject anObject1,PhysicalObject anObject2);





    int getItsBlockX() const;
    void setItsBlockX(int value);
    int getItsBlockY() const;
    void setItsBlockY(int value);
    int getItsY() const;
    void setItsY(int value);
    int getItsX() const;
    void setItsX(int value);
};

#endif // PHYSICALOBJECT_H
