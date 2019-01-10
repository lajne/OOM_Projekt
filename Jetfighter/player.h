#ifndef RECT_H
#define RECT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * praent = 0);
    void keyPressEvent (QKeyEvent * event);
public slots:
    void spawn();
};

#endif // RECT_H
