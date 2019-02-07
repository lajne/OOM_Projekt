#ifndef COIN_H
#define COIN_H

#include "powerup.h"


class Coin : public PowerUp
{
public:
    Coin(QGraphicsItem *parent=0, int moveSpeed = 7);

};

#endif // COIN_H
