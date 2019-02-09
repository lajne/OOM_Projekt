#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "sound.h"

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent = 0);
    void keyPressEvent (QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    Sound *sound = new Sound;  // TODO: Move sound to game class
    bool isEnemyCollision();
    bool isShooting();
    bool escKey();
    void movement();

private:
    bool shootPress = false;
    bool leftPress = false;
    bool rightPress = false;
    bool escPress = false;
    QList<QGraphicsItem> returnCollidingItemsList();
    QList<QGraphicsItem *> collidingList = collidingItems();
};

#endif // PLAYER_H
