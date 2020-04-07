#include "SoundEffect.hpp"

SoundEffect::SoundEffect(const std::string &filePath) :
    played(false) {

    buffer.loadFromFile(filePath);
    sound.setBuffer(buffer);
}

void SoundEffect::play() {
    sound.play();
}

void SoundEffect::playOnce() {
    if (!played) {
        play();
        played = true;
    }
}


