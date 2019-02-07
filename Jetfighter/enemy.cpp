#include "game.h"
#include "enemy.h"
#include "game.h"
#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QString>
#include <stdlib.h> //rand() -> really large int

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent, int moveSpeed): QObject (), QGraphicsPixmapItem(parent) {
    //Set random x pos
    int random_number = rand() % 700;
    setPos(random_number, 0);
    _moveSpeed = moveSpeed;

    //Drew rect
    setPixmap(QPixmap(":/images/enemy_plane.png"));

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // Every 50 ms the bullet will move
    timer->start(50);

    sound->soundInitiate();
}

void Enemy::stop() {
    timer->stop();
}

void Enemy::setSpeed(int speed) {
    _moveSpeed = speed;
}

void Enemy::move() {
    setPos(x(), y() + this->_moveSpeed);
};
