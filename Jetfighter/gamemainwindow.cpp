#include "gamemainwindow.h"
#include "ui_gamemainwindow.h"

GameMainWindow::GameMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameMainWindow)
{
    ui->setupUi(this);
}

GameMainWindow::~GameMainWindow()
{
    delete ui;
}

void GameMainWindow::on_playButton_clicked()
{
    game = new Game();
}

void GameMainWindow::on_quitButton_clicked()
{
    QApplication::quit();
}


