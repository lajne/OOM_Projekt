#include "game.h"
#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>

extern Game * game; //there is an external global object called game.

Bullet::Bullet(QGraphicsItem *parent): QObject (), QGraphicsPixmapItem(parent) {
    //Draw graphics
    setPixmap(QPixmap(":/images/bullet4.png"));

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // Every 50 ms the bullet will move
    timer->start(50);

    sound->soundInitiate();
}

void Bullet::stop() {
    timer->stop();
}

void Bullet::move() {
    setPos(x(), y() - 10);
};
