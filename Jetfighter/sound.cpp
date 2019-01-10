#include "sound.h"
#include <QDebug>

Sound::Sound() {

}

void Sound::soundInitiate() {
    shootSound.setSource(QUrl::fromLocalFile("/sounds/bullet.wav"));
}

void::Sound::soundShoot() {
    if(shootSound.isPlaying()) {
        shootSound.stop();
    }
    shootSound.play();
    qDebug() << "PEW";
}


//KOMMER INGET LJUD?
