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
#include "powerup.h"
#include <QKeyEvent>

class Game: public QGraphicsView {
    Q_OBJECT
public:
    Game(QWidget * parent = 0);
    void spawnEnemy();
    void spawnBullet();
    //Test
    void keyPressEvent (QKeyEvent * event);

    bool gameOver();

//private:
    QGraphicsScene * scene;
    Player * player;
    Enemy * enemy;
    Score * score;
    Health * health;
    PowerUp *powerUp;
    Bullet * bullet;

private:
    std::vector<Enemy*> activeEnemies;
    std::vector<Bullet*> activeBullets;
    Sound *sound = new Sound;
    int spawnTimer;

public slots:
    void gameUpdate();
//    void spawnEnemy();
};

#endif // GAME_H
