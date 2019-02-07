#ifndef LIFEUP_H
#define LIFEUP_H

#include "powerup.h"


class LifeUp : public PowerUp
{
public:
    LifeUp(QGraphicsItem *parent=0, int moveSpeed = 10);

};

#endif // LIFEUP_H
