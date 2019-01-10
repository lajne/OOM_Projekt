#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "sound.h"
#include "player.h"
#include "bullet.h"

class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent = 0);
    Sound *sound = new Sound;
    bool isBulletCollision();

public slots:
    void move();
};

#endif // ENEMY_H
