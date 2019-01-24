#include "game.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>

Game::Game(QWidget *parent){
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

    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

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

