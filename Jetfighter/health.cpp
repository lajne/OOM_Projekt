#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem * parent): QGraphicsTextItem (parent) {
    //Initialize the score to 0
    health = 3;

    //Draw the text
    setPlainText(QString("Health: " + QString::number(health)));    // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease() {
    health--;
    setPlainText(QString("Health: ") + QString::number(health));    //Health: 2
}

int Health::getHealth() {
    return health;
}