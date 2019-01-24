#include "powerup.h"

//#include "game.h"

//extern Game *game;

PowerUp::PowerUp(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //Generate random number and set position
    int randomNumber = 50 + rand() % 700;
    setPos(randomNumber, 0);

    //Draw graphics
    this->setPixmap(QPixmap(":/images/coin.png"));

    //Call move so it moves every 50 ms

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void PowerUp::move()
{
    setPos(x(), y() + 7);
}


//This isn't used atm
void PowerUp::spawn()
{
    //Create new powerUp
    PowerUp *powerUp = new PowerUp();
    scene()->addItem(powerUp);
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
