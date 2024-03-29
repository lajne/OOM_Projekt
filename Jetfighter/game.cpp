#include "game.h"
#include "sound.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QDebug>

Game::Game(QWidget *parent){

    spawnEnemyLvl1Timer = 0;
    spawnCoinTimer = 0;
    spawnHealthTimer = 0;
    shootCooldown = 0;
    levelTimer = 600;
    levelCounter = 1;
    sound->soundInitiate();

    // Create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    setBackgroundBrush(QBrush(QImage(":/images/ground.png")));

    //make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    // Create the player
    player = new Player();
    player->setPos(400, 500);

    //Make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Add the player to the scene
    scene->addItem(player);

    // Add gametext
    for(int i = 0; i < 2; i++) {
        text.push_back(new GameText());
        scene->addItem(text[i]);
    }

    //Create score and health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);

    //Create enemy
    QObject::connect(gameTimer, SIGNAL(timeout()), this, SLOT(gameUpdate()));
    gameTimer->start(50);

    QObject::connect(escTimer, SIGNAL(timeout()), this, SLOT(checkForEsc()));
    escTimer->start(50);
    show();
}

Game::~Game() {
    text.clear();
    activeBullets.clear();
    activeEnemies.clear();
    activePowerUps.clear();
    delete player;
    delete score;
    delete health;
    delete scene;
}

void Game::gameUpdate() {
    if(spawnEnemyLvl1Timer == 40) {
        spawnEnemyLvl1();
        spawnEnemyLvl1Timer = 0;
    }
    if(spawnEnemyLvl2Timer == 600) {
        spawnEnemyLvl2();
        spawnEnemyLvl2Timer = 0;
    }
    if(spawnCoinTimer == 60) {
        spawnCoin();
        spawnCoinTimer = 0;
    }
    if(levelTimer == 600) {
        if(levelCounter > 1) {
            sound->soundLevelUp();
        }
        text[0]->level(levelCounter);
        levelTimer = 0;
        levelCounter++;
        enemySpeed += 1;
    }
    if(spawnHealthTimer == 200) {
        spawnHealth();
        spawnHealthTimer = 0;
    }

    shootEvent();

    player->movement();

    if(!activeEnemies.empty()) {
        for(int i = 0; i < activeEnemies.size(); i++) {
            if(health->getHealth() == 0) {
                gameTimer->stop();
                text[1]->gameOver();
                delete  activeEnemies[i];
                activeEnemies.erase(activeEnemies.begin()+i);
            }
            if(isEnemyCollidingWithBullet(activeEnemies[i])) {
                for(int i = 0; i < activeBullets.size(); i++) {
                    if(isBulletCollidingWithEnemy(activeBullets[i])) {
                        sound->soundBulletHit();
                        scene->removeItem(activeBullets[i]);
                        delete activeBullets[i];
                        activeBullets.erase(activeBullets.begin()+i);
                    }
                }

                //Test
                activeEnemies[i]->decreaseHealth();
                if(activeEnemies[i]->isDead()) {
                    score->increase();
                    scene->removeItem(activeEnemies[i]);
                    delete activeEnemies[i];
                    activeEnemies.erase(activeEnemies.begin()+i);
                }

            }
            if(isEnemyCollidingWithPlayer(activeEnemies[i])) {
                sound->soundExplosion();
                health->setZero();
            }
            if(activeEnemies[i]->pos().y() > 600) {
                health->decrease();
                scene->removeItem(activeEnemies[i]);
                delete activeEnemies[i];
                activeEnemies.erase(activeEnemies.begin()+i);
            }
        }
    }

    if(!activeBullets.empty()) {
        for(int i = 0; i < activeBullets.size(); i++) {
            if(activeBullets[i]->pos().y() < 0) {
                delete activeBullets[i];
                activeBullets.erase(activeBullets.begin()+i);
            }
        }
    }

    spawnEnemyLvl1Timer++;
    spawnEnemyLvl2Timer++;
    spawnCoinTimer++;
    spawnHealthTimer++;
    shootCooldown++;
    levelTimer++;

    //Power ups
    for(int i=0; i<activePowerUps.size(); i++) {
        if(isCoinPickedUp(activePowerUps[i])) {
            sound->soundCoin();
            scene->removeItem(activePowerUps[i]);
            score->increase();
            delete activePowerUps[i];
            activePowerUps.erase(activePowerUps.begin()+i);
        }
        if(isHealthPickedUp(activePowerUps[i])) {
            scene->removeItem(activePowerUps[i]);
            health->increase();
            sound->soundHealthUp();
            delete activePowerUps[i];
            activePowerUps.erase(activePowerUps.begin()+i);
        }
        if(activePowerUps[i]->isOutOfScreen(600)) {
            scene->removeItem(activePowerUps[i]);
            delete activePowerUps[i];
            activePowerUps.erase(activePowerUps.begin()+i);
        }
    }
}

void Game::checkForEsc() {
    if(player->escKey()) {
        hide();
        this->~Game();
    }
}

void Game::spawnEnemyLvl1(){
    activeEnemies.push_back(new EnemyLvl1(enemySpeed));
    scene->addItem(activeEnemies.back());
}

void Game::spawnEnemyLvl2() {
    activeEnemies.push_back(new EnemyLvl2(enemySpeed));
    scene->addItem(activeEnemies.back());
}

void Game::spawnBullet() {
    activeBullets.push_back(new Bullet());
    activeBullets.back()->setPos(player->x() + 40, player->y());
    scene->addItem(activeBullets.back());
}

bool Game::isEnemyCollidingWithBullet(Enemy *enemy) {
    QList<QGraphicsItem *> enemy_collides = enemy->collidingItems();
        for(int i = 0, n = enemy_collides.size(); i < n; ++i) {
            if(typeid (*(enemy_collides[i])) == typeid (Bullet)) {
                return true;
            }
        }
    return false;
}

bool Game::isEnemyCollidingWithPlayer(Enemy *enemy) {
    QList<QGraphicsItem *> enemy_collides = enemy->collidingItems();
        for(int i = 0, n = enemy_collides.size(); i < n; ++i) {
            if(typeid (*(enemy_collides[i])) == typeid (Player)) {
                return true;
            }
        }
        return false;
}

bool Game::isBulletCollidingWithEnemy(Bullet *bullet) {
    QList<QGraphicsItem *> bullet_collides = bullet->collidingItems();
        for(int i = 0, n = bullet_collides.size(); i < n; ++i) {
            if(typeid(*(bullet_collides[i])) == typeid (EnemyLvl1) ||
               typeid(*(bullet_collides[i])) == typeid(EnemyLvl2)) {
                return true;
            }
        }
        return false;
}

void Game::shootEvent() {
    if(player->isShooting()) {
        if(shootCooldown > 0){
            spawnBullet();
            sound->soundShoot();
            shootCooldown = -10;
        }
    }
}

void Game::spawnCoin() {
    activePowerUps.push_back(new Coin());
    scene->addItem(activePowerUps.back());
}

bool Game::isCoinPickedUp(PowerUp *pu) {
    QList<QGraphicsItem *> collidingList = pu->collidingItems();
    for(int i=0; i<collidingList.size(); i++) {
        if(typeid (*(collidingList[i])) == typeid (Player) && typeid(*pu) == typeid(Coin)) {
            return true;
        }
    }
    return false;
}

void Game::spawnHealth() {
    activePowerUps.push_back(new LifeUp());
    scene->addItem(activePowerUps.back());
}

bool Game::isHealthPickedUp(PowerUp *pu) {
    QList<QGraphicsItem *> collidingList = pu->collidingItems();
    for(int i=0; i<collidingList.size(); i++) {
        if(typeid (*(collidingList[i])) == typeid (Player) && typeid(*pu) == typeid(LifeUp)) {
            return true;
        }
    }
    return false;
}
