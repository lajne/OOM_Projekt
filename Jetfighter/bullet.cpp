#include "bullet.h"
#include <QTimer>

Bullet::Bullet() {
    //Drew rect
    setRect(0, 0, 10, 50);

    //Connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // Every 50 ms the bullet will move
    timer->start(50);
}

void Bullet::move() {
    //Move bullet up
    setPos(x(), y() - 10);
};
