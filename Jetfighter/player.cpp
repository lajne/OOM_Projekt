#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    //Set graphics
    setPixmap(QPixmap(":/images/player_plane.png"));
    //Initiate sound
    sound->soundInitiate();
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        if(pos().x() > 0){
            setPos(x() - 10, y());
        }
    } else if(event->key() == Qt::Key_Right) {
        if(pos().x() < 800) {
            setPos(x() + 10, y());
        }
    } else if(event->key() == Qt::Key_Space) {
        //create bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x() + 40, y());
        scene()->addItem(bullet);

        sound->soundShoot();
    }
}

bool Player::isEnemyCollision() {
    //If bullet collide with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0, n = colliding_items.size(); i < n; ++i) {
        if(typeid (*(colliding_items[i])) == typeid (Enemy)) {
            return true;
        }
    }
    return false;
}

//void Player::spawn() {
//    //Create enemy
//    Enemy * enemy = new Enemy();
//    scene()->addItem(enemy);
//}
