#include "sound.h"
#include <QDebug>

Sound::Sound() {

}

void Sound::soundInitiate() {
    shootSound.setSource(QUrl::fromLocalFile(":/sounds/gunfire.wav"));
    explosionSound.setSource(QUrl::fromLocalFile(":/sounds/explosion2.wav"));
    bulletHitSound.setSource(QUrl::fromLocalFile(":/sounds/gunfire.wav"));
    coinHitSound.setSource(QUrl::fromLocalFile(":/sounds/coin.wav"));
    healthUpSound.setSource(QUrl::fromLocalFile(":/sounds/healthup.wav"));
    levelUpSound.setSource(QUrl::fromLocalFile(":/sounds/lvlup2.wav"));
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

void Sound::soundHealthUp(){
    healthUpSound.play();
}

void Sound::soundLevelUp() {
    levelUpSound.play();
}


//KOMMER INGET LJUD?
