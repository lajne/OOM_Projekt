#include "game.h"
#include "sound.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QDebug>

Game::Game(QWidget *parent){

    spawnTimer = 0;
    shootCooldown = 0;
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
//    qDebug() << "player in scene";

    //Make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Add the player to the scene
    scene->addItem(player);

    //Create score and health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);

//    //spawn enemies
//    QTimer * timer = new QTimer();
//    //Create enemy
//    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
//    timer->start(2000);

    //spawn enemies
    QTimer * gameTimer = new QTimer();
    //Create enemy
    QObject::connect(gameTimer, SIGNAL(timeout()), this, SLOT(gameUpdate()));
    gameTimer->start(50);

    //PowerUp
    //powerUp = new PowerUp();

    //scene->addItem(powerUp);
    QTimer *timer2 = new QTimer();
    QObject::connect(timer2, SIGNAL(timeout()), player, SLOT(spawn2()));
    timer2->start(1000);

    if(!player->isVisible()) {
        this->close();
    }

    show();
}

bool Game::gameOver() {

}

void Game::gameUpdate() {
    //20
    if(spawnTimer == 40) {
        spawnEnemy();
        spawnTimer = 0;
    }
    shootEvent();



    if(!activeEnemies.empty()) {
        for(int i = 0; i < activeEnemies.size(); i++) {
            if(isEnemyCollidingWithBullet(activeEnemies[i])) {
                for(int i = 0; i < activeBullets.size(); i++) {
                    if(isBulletCollidingWithEnemy(activeBullets[i])) {
                        scene->removeItem(activeBullets[i]);
                        delete activeBullets[i];
                        activeBullets.erase(activeBullets.begin()+i);
                    }
                }
                score->increase();
                scene->removeItem(activeEnemies[i]);
                delete activeEnemies[i];
                activeEnemies.erase(activeEnemies.begin()+i);
            }
            if(isEnemyCollidingWithPlayer(activeEnemies[i])) {
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
    spawnTimer++;
    shootCooldown++;
}

void Game::spawnEnemy(){
    activeEnemies.push_back(new Enemy());
    scene->addItem(activeEnemies.back());
};

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
            if(typeid (*(bullet_collides[i])) == typeid (Enemy)) {
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
