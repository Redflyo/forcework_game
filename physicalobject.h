#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H


class PhysicalObject
{
protected:
    int itsX;
    int itsY;
    int itsWidth;
    int itsHeight;
public:
    PhysicalObject();
    ///
    /// \brief isCollide
    /// \param anObject1
    /// \param anObject2
    /// \return
    static int isCollide(PhysicalObject anObject1,PhysicalObject anObject2);

};

#endif // PHYSICALOBJECT_H
