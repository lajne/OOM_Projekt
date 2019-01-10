#include "game.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QDebug>

Game::Game(QWidget *parent){

    spawnTimer = 0;

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

    show();
}

void Game::gameOver() {

}

void Game::gameUpdate() {
    if(spawnTimer == 40) {
        spawnEnemy();
        spawnTimer = 0;
    }

    if(enemy->isBulletCollision()) {
////        qDebug() << "isbulletcollision!";
    }
    if(player->isEnemyCollision()) {
        qDebug() << "isenemycollision!";
    }
//    else {
////        qDebug() << "KINA ATTACKAREREREREER";
//    }

    spawnTimer++;
}

void Game::spawnEnemy(){
    //Create enemy
    Enemy * enemy = new Enemy();
    scene->addItem(enemy);
};
