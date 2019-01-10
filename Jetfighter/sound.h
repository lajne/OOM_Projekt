#ifndef SOUND_H
#define SOUND_H

#include <QSoundEffect>

using namespace std;

class Sound: public QSoundEffect {
  public:
    Sound();
    void soundInitiate();
    void soundShoot();
private:
    QSoundEffect shootSound;
};

#endif // SOUND_H
