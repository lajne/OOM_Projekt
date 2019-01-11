#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QFont>
#include <QObject>
#include "player.h"
#include "enemy.h"
#include "score.h"
#include "health.h"

class Game: public QGraphicsView {
    Q_OBJECT
public:
    Game(QWidget * parent = 0);
    void gameOver();
    void spawnEnemy();

//private:
    QGraphicsScene * scene;
    Player * player;
    Enemy * enemy;
    Score * score;
    Health * health;

private:
    std::vector<Enemy*> activeEnemies;
    Sound *sound = new Sound;
    int spawnTimer;

public slots:
    void gameUpdate();
//    void spawnEnemy();
};

#endif // GAME_H
