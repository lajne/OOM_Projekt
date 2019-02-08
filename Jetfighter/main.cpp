#include <QApplication>
#include "gamemainwindow.h"
//#include "game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameMainWindow gmw;
    gmw.show();

    return a.exec();
}
