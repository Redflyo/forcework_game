#include "bullet.h"
///
/// \brief Bullet::Bullet
///
Personnage *Bullet::getItsOwner() const
{
    return itsOwner;
}

Bullet::Bullet(Personnage *owner)
{
    itsOwner = owner;
}
