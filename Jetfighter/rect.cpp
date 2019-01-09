#include "rect.h"
#include "bullet.h"
#include <QGraphicsScene>
#include <QKeyEvent>

void Rect::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        setPos(x() - 10, y());
    } else if(event->key() == Qt::Key_Right) {
        setPos(x() + 10, y());
    } else if(event->key() == Qt::Key_Up) {
        setPos(x(), y() - 10);
    } else if(event->key() == Qt::Key_Down) {
        setPos(x(), y() + 10);
    }
    else if(event->key() == Qt::Key_Space) {
        //create bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
}
