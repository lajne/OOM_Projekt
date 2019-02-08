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
#include "gametext.h"
#include <QKeyEvent>

class Game: public QGraphicsView {
    Q_OBJECT
public:
    Game(QWidget * parent = 0);
    ~Game();
    //void keyPressEvent (QKeyEvent * event);
    void spawnEnemy();
    void spawnBullet();
    bool isEnemyCollidingWithBullet(Enemy * enemy);
    bool isEnemyCollidingWithPlayer(Enemy *enemy);
    bool isBulletCollidingWithEnemy(Bullet *bullet);
    void shootEvent();
    bool gameOver();
    void setGameOverText();

//private:
    QGraphicsScene * scene;
    QTimer * gameTimer = new QTimer;
    Player * player;
    Enemy * enemy;
    Score * score;
    Health * health;
    PowerUp *powerUp;
    Bullet * bullet;
    GameText * gameText;
    bool isCoinPickedUp(PowerUp *pu);
    bool isHealthPickedUp(PowerUp *pu);
  
private:
    std::vector<Enemy*> activeEnemies;
    std::vector<Bullet*> activeBullets;
    std::vector<PowerUp*> activePowerUps;
    std::vector<GameText*> text;     //text[0] = level, text[1] = gameover
    Sound *sound = new Sound;
    int spawnEnemyTimer, spawnCoinTimer, shootCooldown, spawnHealthTimer, levelTimer, levelCounter;
    int enemySpeed = 5;

public slots:
    void gameUpdate();
    void spawnCoin();
    void spawnHealth();
};

#endif // GAME_H
