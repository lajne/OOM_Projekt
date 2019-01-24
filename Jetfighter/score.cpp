#include "score.h"
#include <QFont>


Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    //Initialize the score to 0
    score = 0;

    //Draw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 24));
}

void Score::increase() {
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore() {
    return score;
}
