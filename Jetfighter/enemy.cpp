#include "game.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <stdlib.h> //rand() -> really large int

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject (), QGraphicsPixmapItem(parent) {
    //Set random x pos
    int random_number = rand() % 700;
    setPos(random_number, 0);

    //Drew rect
    setPixmap(QPixmap(":/images/enemy_plane.png"));

    //make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // Every 50 ms the bullet will move
    timer->start(50);

    sound->soundInitiate();
}

// check if collision with bullet
bool Enemy::isBulletCollision() {
    //If bullet collide with enemy, destroy both
//    QList<QGraphicsItem *> colliding_items = collidingItems();

//    for(int i = 0, n = colliding_items.size(); i < n; ++i) {
//        if(typeid (*(colliding_items[i])) == typeid (Bullet)) {
//            //Increase score
//            game->score->increase();
//            sound->soundBulletHit();

//            //Remove them both
//            scene()->removeItem(colliding_items[i]);
//            scene()->removeItem(this);

//            //Delete them both
//            delete colliding_items[i];
//            delete this;

//            qDebug() << "Enemy deleted by collision";
            return true;
//        }
//    }
//    return false;
}

void Enemy::move() {
    //Move enemy down
    setPos(x(), y() + 5);

    if(pos().y() > 600) {
        //decrease health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;

        qDebug() << "Enemy deleted by end of scene";
    }
};
