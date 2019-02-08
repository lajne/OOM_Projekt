#include "enemylvl1.h"

EnemyLvl1::EnemyLvl1(int moveSpeed, QGraphicsItem *parent) : Enemy(moveSpeed, 1, parent)
{
    setPixmap(QPixmap(":/images/enemy_plane.png"));
}
