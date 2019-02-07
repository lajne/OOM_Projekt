#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QFont>
#include <QObject>
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "score.h"
#include "health.h"
#include "powerup.h"
#include "coin.h"
#include "lifeup.h"
#include <QKeyEvent>

class Game: public QGraphicsView {
    Q_OBJECT
public:
    Game(QWidget * parent = 0);
    void spawnEnemy();
    void spawnBullet();
    bool isEnemyCollidingWithBullet(Enemy * enemy);
    bool isEnemyCollidingWithPlayer(Enemy *enemy);
    bool isBulletCollidingWithEnemy(Bullet *bullet);
    void shootEvent();
    bool gameOver();

//private:
    QGraphicsScene * scene;
    Player * player;
    Enemy * enemy;
    Score * score;
    Health * health;
    PowerUp *powerUp;
    Bullet * bullet;
    //bool isPlayerCollidingWithPowerUp(Player *player);
    bool isCoinPickedUp(PowerUp *pu);
    bool isHealthPickedUp(PowerUp *pu);
private:
    std::vector<Enemy*> activeEnemies;
    std::vector<Bullet*> activeBullets;
    std::vector<PowerUp*> activePowerUps;
    Sound *sound = new Sound;
    int spawnEnemyTimer, spawnPowerUpTimer, shootCooldown;


public slots:
    void gameUpdate();
//    void spawnEnemy();
    void spawnCoin();
    void spawnHealth();
};

#endif // GAME_H
