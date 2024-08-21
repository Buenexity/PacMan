#include "../header/backgroundSounds.h"

void SoundBack::wakawaka() {
    if (!soundBuffer.loadFromFile("SoundsForGame/WakaWaka.wav")) {
        std::cout << "can't find waka file" << std::endl;
    }
    sound.setBuffer(soundBuffer);
    sound.setVolume(15.0f);
    sound.play();
}


void SoundBack::powerUp() {
    if (!soundBuffer.loadFromFile("SoundsForGame/powerUp.wav")) {
        std::cout << "can't find powerUp file" << std::endl;
    }
    sound.setBuffer(soundBuffer);
    sound.setVolume(15.0f);
    sound.play();
}

void SoundBack::loadScreen() {
    if (!soundBuffer.loadFromFile("SoundsForGame/loading.wav")) {
        std::cout << "can't find loading file" << std::endl;
    }
    sound.setBuffer(soundBuffer);
    sound.setVolume(15.f);
    sound.play();
}

void SoundBack::sackDead() {
    if (!soundBuffer.loadFromFile("SoundsForGame/death.wav")) {
        std::cout << "can't find death file" << std::endl;
    }
    sound.setBuffer(soundBuffer);
    sound.setVolume(15.f);
    sound.play();
}