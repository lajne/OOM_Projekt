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
//bool Enemy::isBulletCollision(Enemy *enemy) {

//    //If bullet collide with enemy, destroy both
//    QList<QGraphicsItem *> colliding_bullets = enemy->collidingItems();
//        //qDebug() << "2" << colliding_bullets;
//        for(int i = 0, n = colliding_bullets.size(); i < n; ++i) {
//            if(typeid (*(colliding_bullets[i])) == typeid (Bullet)) {
//                return true;
//            }
//        }
//    return false;
//}

void Enemy::move() {
//    qDebug() << "move enemy";
    //Move enemy down
    setPos(x(), y() + 5);

//    if(pos().y() > 600) {
//        //decrease health
//        game->health->decrease();

//        scene()->removeItem(this);
//        delete this;

//        qDebug() << "Enemy deleted by end of scene";
//    }
};
