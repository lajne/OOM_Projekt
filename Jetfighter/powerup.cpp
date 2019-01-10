#include "powerup.h"
//#include "game.h"

//extern Game *game;

PowerUp::PowerUp(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //Generate random number and set position
    int randomNumber = 50 + rand() % 700;
    this->setPos(randomNumber, 40);

    //Draw graphics
    this->setPixmap(QPixmap(":/images/bullet4.png"));
}

void PowerUp::spawn()
{
    //Create new powerUp
    PowerUp *powerUp = new PowerUp();
    scene()->addItem(powerUp);
}
