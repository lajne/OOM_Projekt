#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem * parent): QGraphicsTextItem (parent) {
    //Initialize the score to 0
    health = 3;

    //Draw the text
    setPlainText(QString("Health: " + QString::number(health)));    // Health: 3
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 24));
}

void Health::increase() {
    health++;
    setPlainText(QString("Health: ") + QString::number(health));
}

void Health::decrease() {
    health--;
    setPlainText(QString("Health: ") + QString::number(health));    //Health: 2
}

int Health::getHealth() {
    return health;
}

void Health::setZero() {
    health = 0;
    setPlainText(QString("Health: ") + QString::number(health));
}
