#include <QApplication>
#include <QGraphicsScene>
#include "rect.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // Create an item to put into the scene
    Rect * rect = new Rect();
    rect->setRect(0, 0, 100, 100);

    // Add item to the scene
    scene->addItem(rect);

    //Make the item focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //Create view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);               //SLUTADE HÄR!!!

    // Show the view
    view->show();

    return a.exec();
}
