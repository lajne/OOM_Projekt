#ifndef POWERUP_H
#define POWERUP_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
//#include "game.h"
#include <stdlib.h>

//May remove later
#include "player.h"

class PowerUp : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PowerUp(QGraphicsItem *parent = 0);
    //bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape);

    //Put all the items that collides with a powerUp here
    //QList<QGraphicsItem *> list = collidingItems() ;

    bool isOutOfScreen();
public slots:
    void move();

    void spawn();

    //bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape);
    //bool collidesWithPlayer(const Player  *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) : QGraphicsItem::collidesWithItem(*other, Qt::IntersectsItemShape) {}
};

#endif // POWERUP_H
