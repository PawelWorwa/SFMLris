#ifndef SFMLRIS_SOUNDEFFECT_HPP
#define SFMLRIS_SOUNDEFFECT_HPP

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class SoundEffect {
    public:
        explicit SoundEffect(const std::string &filePath);

        void play();
        void playOnce();

    private:
        sf::SoundBuffer buffer;
        sf::Sound sound;

        bool played;
};


#endif //SFMLRIS_SOUNDEFFECT_HPP
