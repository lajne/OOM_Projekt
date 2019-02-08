#include "enemylvl2.h"

EnemyLvl2::EnemyLvl2(int moveSpeed, QGraphicsItem *parent) : Enemy(moveSpeed, 2, parent)
{
    setPixmap(QPixmap(":/images/enemy2_plane.png"));
}
