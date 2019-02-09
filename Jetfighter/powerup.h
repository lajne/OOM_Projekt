#ifndef POWERUP_H
#define POWERUP_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
//#include "game.h"
#include <stdlib.h>

//May remove later
#include "player.h"

class PowerUp : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PowerUp(QGraphicsItem *parent = 0, int moveSpeed = 0);

    bool isOutOfScreen(int screenHeight);
    void stop();

public slots:
    void move();

private:
    QTimer * timer = new QTimer();
    int _moveSpeed;
};

#endif // POWERUP_H
