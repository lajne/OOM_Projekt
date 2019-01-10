#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "player.h"
//#include "arena.h"
#include "sound.h"

class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    //Parametrar: (Arena * a, Player * p, QGraphicsItem * parent = 0)
    Bullet(QGraphicsItem * parent = 0);
    Sound *sound = new Sound;

//SKA VI HA ?
//private:
//    Sound *sound;
//    Arena * arena;
//    Player *player;
//    QTimer *timer;

public slots:
    void move();
};

#endif // BULLET_H
