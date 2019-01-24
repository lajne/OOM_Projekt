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
    void movement();

private:
    bool shootPress = false;
    bool leftPress = false;
    bool rightPress = false;
    QList<QGraphicsItem> returnCollidingItemsList();
    QList<QGraphicsItem *> collidingList = collidingItems();
//public slots:
//    void spawn();
public slots:

    //Will remove later
    //void spawn2();
};

#endif // PLAYER_H
