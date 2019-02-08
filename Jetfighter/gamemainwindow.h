#ifndef GAMEMAINWINDOW_H
#define GAMEMAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include "game.h"

namespace Ui {
class GameMainWindow;
}

class GameMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameMainWindow(QWidget *parent = 0);
    ~GameMainWindow();

private slots:
    void on_playButton_clicked();
    void on_quitButton_clicked();

private:
    Ui::GameMainWindow *ui;
    Game * game;
};

#endif // GAMEMAINWINDOW_H
