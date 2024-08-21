#ifndef BACKGROUNDSOUNDS_H
#define BACKGROUNDSOUNDS_H
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

class SoundBack {
    private:
        sf::SoundBuffer soundBuffer;
        sf::Sound sound;
    public:
        void wakawaka();
        void powerUp();
        void loadScreen();
        void sackDead();
};

#endif