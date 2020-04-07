#include "Texture.hpp"

const std::string Texture::BLOCKS_TEXTURE_PATH = "./media/tetrominos.png";

Texture::Texture() {
    blocksTexture.loadFromFile(BLOCKS_TEXTURE_PATH);
}

const sf::Texture &Texture::getBlocksTexture() const {
    return blocksTexture;
}

const unsigned int Texture::getBlocksInTexture() const {
    return BLOCKS_IN_TEXTURES;
}