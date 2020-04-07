#ifndef SFMLRIS_MEDIA_HPP
#define SFMLRIS_MEDIA_HPP

#include <string>

#include <SFML/Graphics/Texture.hpp>

class Texture {
    public:
        Texture();

        const sf::Texture &getBlocksTexture() const;
        const unsigned int getBlocksInTexture() const;

    private:
        static const std::string BLOCKS_TEXTURE_PATH;

        static const unsigned int BLOCKS_IN_TEXTURES = 8;

        sf::Texture blocksTexture;
};

#endif //SFMLRIS_MEDIA_HPP
