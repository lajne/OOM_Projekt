#include "sound.h"
#include <QDebug>

Sound::Sound() {

}

void Sound::soundInitiate() {
    shootSound.setSource(QUrl::fromLocalFile(":/sounds/gunfire.wav"));
    propellerSound.setSource(QUrl::fromLocalFile(":/sounds/prop.wav"));
}

void Sound::soundShoot() {
    if(shootSound.isPlaying()) {
        shootSound.stop();
    }
    shootSound.play();
}

//Background sound isn't working, maybe don't need it?
void Sound::soundPropeller() {
    propellerSound.play();
}


//KOMMER INGET LJUD?
