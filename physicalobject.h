#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include <QMainWindow>

class PhysicalObject
{
protected:
    int itsBlockX, itsBlockY;
    int itsX;
    int itsY;
    int itsWidth;
    int itsHeight;
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
