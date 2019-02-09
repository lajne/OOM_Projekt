#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "player.h"
#include <QTimer>
#include "sound.h"

class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent = 0);
    Sound *sound = new Sound;
    void stop();

private:
    QTimer * timer = new QTimer();

public slots:
    void move();
};

#endif // BULLET_H
