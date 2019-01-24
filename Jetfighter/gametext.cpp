#include "gametext.h"

GameText::GameText(QGraphicsItem *parent): QGraphicsTextItem (parent) {
    //this->setScale(5);
    this->setDefaultTextColor(Qt::white);
    //this->setTransformOriginPoint(this->boundingRect().center());
}

void GameText::gameOver() {
    this->setPos(300,300);
    this->setPlainText(QString("Game Over"));
//    setScale(10);
}
