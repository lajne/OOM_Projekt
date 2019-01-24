#ifndef GAMETEXT_H
#define GAMETEXT_H
#include <QGraphicsTextItem>

class GameText: public QGraphicsTextItem
{
public:
    GameText(QGraphicsItem * parent = 0);
    void gameOver();
};

#endif // GAMETEXT_H
