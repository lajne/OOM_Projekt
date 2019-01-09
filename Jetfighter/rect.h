#ifndef RECT_H
#define RECT_H

#include <QGraphicsRectItem>

class Rect: public QGraphicsRectItem{
public:
    void keyPressEvent (QKeyEvent * event);
};

#endif // RECT_H
