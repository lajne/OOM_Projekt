#ifndef POWERUP_H
#define POWERUP_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
//#include "game.h"
#include <stdlib.h>

class PowerUp : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PowerUp(QGraphicsItem *parent = 0);

public slots:
    void move();

    void spawn();
};

#endif // POWERUP_H