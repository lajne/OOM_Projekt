#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "health.h"
#include "powerup.h"
#include <QKeyEvent>

class Game: public QGraphicsView {
public:
    Game(QWidget * parent = 0);
    //Test
    //void keyPressEvent (QKeyEvent * event);

    //bool gameOver();

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    PowerUp *powerUp;
};

#endif // GAME_H
