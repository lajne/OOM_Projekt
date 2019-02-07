#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include "sound.h"
#include "player.h"
#include "bullet.h"

class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent = 0, int moveSpeed = 0);
    Sound *sound = new Sound;
    void stop();
    void setSpeed(int speed);

private:
    QTimer * timer = new QTimer();
    int _moveSpeed;

public slots:
    void move();
};

#endif // ENEMY_H
