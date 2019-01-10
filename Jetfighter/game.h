#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
//TODO: include healt score

class Game: public QGraphicsView {
public:
    Game(QWidget * parent = 0);

    QGraphicsScene * scene;
    Player * player;
    //score health
};

#endif // GAME_H
