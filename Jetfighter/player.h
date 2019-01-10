#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include "sound.h"

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent = 0);
    void keyPressEvent (QKeyEvent * event);
    Sound *sound = new Sound;  // TODO: Move sound to game class
public slots:
    void spawn();
};

#endif // PLAYER_H
