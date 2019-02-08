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
        leftPress = true;
    } else if(event->key() == Qt::Key_Right) {
        rightPress = true;
    } else if(event->key() == Qt::Key_Space) {
        shootPress = true;
    } else if (event->key() == Qt::Key_Escape) {
        escPress = true;
    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Left) {
        leftPress = false;
    } else if (event->key() == Qt::Key_Right) {
        rightPress = false;
    } else if(event->key() == Qt::Key_Space) {
        shootPress = false;
    } else if (event->key() == Qt::Key_Escape) {
        escPress = false;
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

bool Player::isShooting() {
    if(shootPress) {
        return true;
    } else {
        return false;
    }
}

bool Player::escKey() {
    return escPress;
}

void Player::movement() {
    if(leftPress) {
        if(pos().x() > 0){
            setPos(x() - 10, y());
        }
    } else if (rightPress) {
        if(pos().x() < 800) {
            setPos(x() + 10, y());
        }
    }
}
