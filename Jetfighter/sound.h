#ifndef SOUND_H
#define SOUND_H

#include <QSoundEffect>

using namespace std;

class Sound: public QSoundEffect {
  public:
    Sound();
    void soundInitiate();
    void soundShoot();
    void soundPropeller();
private:
    QSoundEffect shootSound;
    QSoundEffect propellerSound;
};

#endif // SOUND_H
