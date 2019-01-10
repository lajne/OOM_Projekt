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
    Sound *sound = new Sound;  // TODO: Move sound to game class
    bool isEnemyCollision();
//public slots:
//    void spawn();
};

#endif // PLAYER_H
