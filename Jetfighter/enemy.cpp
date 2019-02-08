#include "game.h"
#include "enemy.h"
#include "game.h"
#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QString>
#include <stdlib.h>

extern Game * game;

Enemy::Enemy(int moveSpeed, int health, QGraphicsItem *parent): QObject (), QGraphicsPixmapItem(parent) {
    //Set random x pos
    int random_number = rand() % 700;
    setPos(random_number, 0);
    this->setSpeed(moveSpeed);
    this->setHealth(health);

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

void Enemy::setHealth(int health) {
    _health = health;
}

void Enemy::move() {
    setPos(x(), y() + this->_moveSpeed);
}

void Enemy::decreaseHealth() {
    _health--;
}

bool Enemy::isDead() {
    if(_health == 0) {
        return true;
    }
    return false;
}
