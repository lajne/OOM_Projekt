#include "coin.h"

Coin::Coin(QGraphicsItem *parent, int moveSpeed) : PowerUp(parent, moveSpeed)
{
    this->setPixmap(QPixmap(":/images/coin.png"));
}
