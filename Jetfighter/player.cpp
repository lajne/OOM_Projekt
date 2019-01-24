#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QString>
#include <QDebug>

#include "powerup.h"

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
    } else if(event->key() == Qt::Key_X) {
        this->hide();
    }
}

//Take action straight away.
bool Player::isEnemyCollision() {
    //If bullet collide with enemy, destroy both
    QList<QGraphicsItem *> colliding_enemies = collidingItems();
    //qDebug() << "colliding_enemies: " << colliding_enemies;
    for(int i = 0, n = colliding_enemies.size(); i < n; ++i) {
        if(typeid (*(colliding_enemies[i])) == typeid (Enemy)) {
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
//Will remove later
void Player::spawn2() {
    PowerUp *powerUp = new PowerUp();
    scene()->addItem(powerUp);
}
