#-------------------------------------------------
#
# Project created by QtCreator 2019-01-09T12:44:57
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Jetfighter
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    player.cpp \
    score.cpp \
    health.cpp \
    sound.cpp \
    powerup.cpp \
    coin.cpp \
    lifeup.cpp \
    gametext.cpp \
    enemylvl2.cpp \
    enemylvl1.cpp \
    gamemainwindow.cpp


HEADERS += \
    bullet.h \
    enemy.h \
    game.h \
    player.h \
    score.h \
    health.h \
    sound.h \
    powerup.h \
    coin.h \
    lifeup.h \
    gametext.h \
    enemylvl2.h \
    enemylvl1.h \
    gamemainwindow.h

FORMS += \
    gamemainwindow.ui

RESOURCES += \
    res.qrc
