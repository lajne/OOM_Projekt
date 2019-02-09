#include "powerup.h"

PowerUp::PowerUp(QGraphicsItem *parent, int moveSpeed) : QObject(), QGraphicsPixmapItem(parent)
{
    //Generate random number and set position
    int randomNumber = 50 + rand() % 700;
    setPos(randomNumber, 0);
    this->_moveSpeed = moveSpeed;

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void PowerUp::move()
{
    setPos(x(), y() + this->_moveSpeed);
}

bool PowerUp::isOutOfScreen(int screenHeight)
{
    if(pos().y() > screenHeight) {
        return true;
    }
    return false;
}

void PowerUp::stop()
{
    timer->stop();
}
