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
    Enemy(int moveSpeed, int health, QGraphicsItem * parent = 0);
    Sound *sound = new Sound;
    void stop();
    void setSpeed(int speed);
    void setHealth(int health);
    void decreaseHealth();
    bool isDead();

private:
    QTimer * timer = new QTimer();
    int _moveSpeed;
    int _health;

public slots:
    void move();
};

#endif // ENEMY_H
