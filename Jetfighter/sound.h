#ifndef SOUND_H
#define SOUND_H

#include <QSoundEffect>

using namespace std;

class Sound: public QSoundEffect {
  public:
    Sound();
    void soundInitiate();
    void soundShoot();
    void soundExplosion();
    void soundBulletHit();
    void soundCoin();
private:
    QSoundEffect shootSound;
    QSoundEffect explosionSound;
    QSoundEffect bulletHitSound;
    QSoundEffect coinHitSound;
};

#endif // SOUND_H
