#include "gametext.h"
#include <QDebug>
#include <QFont>

GameText::GameText(QGraphicsItem *parent): QGraphicsTextItem (parent) {
    setDefaultTextColor(Qt::white);
    setFont(QFont("times, 24"));
}

void GameText::position(int x, int y) {
    this->setPos(x, y);
}



void GameText::gameOver() {
    this->setPos(110, 150);
    setPlainText(QString("Game Over"));
    setScale(10);
}
