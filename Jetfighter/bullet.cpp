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

    //make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // Every 50 ms the bullet will move
    timer->start(50);

    sound->soundInitiate();
}

void Bullet::move() {
//    //If bullet collide with enemy, destroy both
//    QList<QGraphicsItem *> colliding_items = collidingItems();

//    for(int i = 0, n = colliding_items.size(); i < n; ++i) {
//        if(typeid (*(colliding_items[i])) == typeid (Enemy)) {
//            //Increase score
//            game->score->increase();    //Not here
//            sound->soundBulletHit();

//            //Remove them both
//            scene()->removeItem(colliding_items[i]);
//            scene()->removeItem(this);

//            //Delete them both
//            delete colliding_items[i];
//            delete this;

//            qDebug() << "Enemy deleted by collision";
//            return;
//        }
//    }

    //if no collisions with enemies, move the bullet forward
    setPos(x(), y() - 10);

    // If the bullet is off the screen, destroy it
    if(pos().y() < 0) {
        scene()->removeItem(this);
        delete this;

        qDebug() << "Bullet deleted";
    }
};
