#include "lifeup.h"

LifeUp::LifeUp(QGraphicsItem *parent, int moveSpeed) : PowerUp(parent, moveSpeed)
{
    this->setPixmap(QPixmap(":/images/heart.png"));
}
