#include "sound.h"
#include <QDebug>

Sound::Sound() {

}

void Sound::soundInitiate() {
    shootSound.setSource(QUrl::fromLocalFile(":/sounds/gunfire.wav"));
    explosionSound.setSource(QUrl::fromLocalFile(":/sounds/explosion2.wav"));
    bulletHitSound.setSource(QUrl::fromLocalFile(":/sounds/gunfire.wav"));
    coinHitSound.setSource(QUrl::fromLocalFile(":/sounds/coin.wav"));
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
    bulletHitSound.play();
}

void Sound::soundCoin() {
    coinHitSound.play();
}


//KOMMER INGET LJUD?
