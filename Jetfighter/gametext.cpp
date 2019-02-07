#include "gametext.h"
#include <QDebug>
#include <QFont>

GameText::GameText(QGraphicsItem *parent): QGraphicsTextItem (parent) {
    setDefaultTextColor(Qt::white);
}

void GameText::position(int x, int y) {
    this->setPos(x, y);
}

void GameText::level(int n) {
    setFont(QFont("times, 14"));
    setPlainText(QString("Level ") + QString::number(n));
    setScale(2);
    this->setPos(715, 0);
}

void GameText::gameOver() {
    setFont(QFont("times, 24"));
    setPlainText(QString("Game Over"));
    setScale(10);
    this->setPos(110, 150);
}
