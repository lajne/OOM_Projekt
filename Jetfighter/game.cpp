#include "game.h"
#include "enemy.h"
#include "sound.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QDebug>

Game::Game(QWidget *parent){

    spawnTimer = 0;
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
    qDebug() << "player in scene";

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
    QObject::connect(timer2, SIGNAL(timeout()), this, SLOT(spawnPowerUp()));
    timer2->start(1000);


    if(!player->isVisible()) {
        this->close();
    }

    show();
}

//void Game::gameOver() {

//}

void Game::gameUpdate() {
    if(spawnTimer == 40) {
        spawnEnemy();
        spawnTimer = 0;
    }
    if(!activeEnemies.empty()) {
        for(int i = 0; i < activeEnemies.size(); i++) {
            //qDebug() << activeEnemies.size();
            if(enemy->isBulletCollision(activeEnemies[i])) {
                qDebug() << "yes!      " << i;
                score->increase();
                //Remove both
                scene->removeItem(activeEnemies[i]);
//                scene->removeItem()
                delete activeEnemies[i];
                activeEnemies.erase(activeEnemies.begin()+i);
            }
            if(activeEnemies[i]->pos().y() > 600) {
                health->decrease();
                scene->removeItem(activeEnemies[i]);
                delete activeEnemies[i];
                activeEnemies.erase(activeEnemies.begin()+i);
            }
        }
    }

//    QList<QGraphicsItem *> scene_items = scene->items();
//    for(int i = 0, n = scene_items.size(); i < n; ++i) {
//        if(typeid (*(scene_items[i])) == typeid (Enemy)){
//            //qDebug() << "Scene contains enemy!!";
//            QList<QGraphicsItem *> colliding_enemies = collidingItems();
//            if(enemy->isBulletCollision()) {
//                //qDebug() << "isbulletcollision!";
//            }
//        }
//    }

    if(player->isEnemyCollision()) {
        qDebug() << "isenemycollision!";
        sound->soundExplosion();
    }
//    else {
////        qDebug() << "KINA ATTACKAREREREREER";
//    }

    spawnTimer++;

    //TESTIS
    for(int i=0; i<activePowerUps.size(); i++) {
        if(isPowerUpPickedUp(activePowerUps[i])) {
            scene->removeItem(activePowerUps[i]);
            score->increase();
            delete activePowerUps[i];
            activePowerUps.erase(activePowerUps.begin()+i);
        }
        if(activePowerUps[i]->isOutOfScreen()) {
            scene->removeItem(activePowerUps[i]);
            delete activePowerUps[i];
            activePowerUps.erase(activePowerUps.begin()+i);
        }
    }
}

void Game::spawnEnemy(){
    //Create enemy
//    Enemy * enemy = new Enemy();
//    scene->addItem(enemy);
    activeEnemies.push_back(new Enemy());
    scene->addItem(activeEnemies.back());
}

void Game::spawnPowerUp() {

    activePowerUps.push_back(new PowerUp());
    scene->addItem(activePowerUps.back());
}

bool Game::isPlayerCollidingWithPowerUp(Player *player) {
    qDebug()<<"im in";
    QList<QGraphicsItem *> collidingList = player->collidingItems();
    if(collidingList.size() > 0) {
        for(int i=0; i<collidingList.size(); i++) {
            if(typeid (*(collidingList[i])) == typeid (PowerUp)) {
                return true;
            }
        }
    }

    return false;
}

bool Game::isPowerUpPickedUp(PowerUp *pu) {
    QList<QGraphicsItem *> collidingList = pu->collidingItems();
    for(int i=0; i<collidingList.size(); i++) {
        if(typeid (*(collidingList[i])) == typeid (Player)) {
            return true;
        }
    }
    return false;
}



//void Game::keyPressEvent(QKeyEvent *event)
//{
//    if (event->key() == Qt::Key_X) {
//        this->close();
//    }
//}

////Pause all timers
//bool Game::gameOver()
//{
//    return true;
//}
