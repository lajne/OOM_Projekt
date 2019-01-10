#include "sound.h"
#include <QDebug>

Sound::Sound() {

}

void Sound::soundInitiate() {
    shootSound.setSource(QUrl::fromLocalFile(":/sounds/gunfire.wav"));
    explosionSound.setSource(QUrl::fromLocalFile(":/sounds/explosion2.wav"));
    bulletHitSound.setSource(QUrl::fromLocalFile(":/sounds/gunfire.wav"));
}

void Sound::soundShoot() {
    if(shootSound.isPlaying()) {
        shootSound.stop();
    }
    shootSound.play();
}

void Sound::soundExplosion() {
    explosionSound.play();
}

void Sound::soundBulletHit() {
    qDebug() << "Hit";
    bulletHitSound.play();
}


//KOMMER INGET LJUD?
