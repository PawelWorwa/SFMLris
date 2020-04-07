#include "NextPieceSection.hpp"

NextPieceSection::NextPieceSection(Texture &texture) : texture(texture) {
    clear();
}

void NextPieceSection::addTetromino(const Block &tetromino) {
    for (auto &piece : tetromino.getPieces()) {
        tetrominoPiece[piece.getXPos()][piece.getYPos()] = tetromino.getBlockType();
    }
}

void NextPieceSection::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    const sf::Texture &blocksTexture = texture.getBlocksTexture();
    unsigned int width = blocksTexture.getSize().x / texture.getBlocksInTexture();
    unsigned int height = blocksTexture.getSize().y;

    for (unsigned int row = 0; row < ROWS; row++) {
        for (unsigned int column = 0; column < COLUMNS; column++) {
            sf::Sprite wellPiece(blocksTexture);
            wellPiece.setPosition(width * row + xOffset, height * column + yOffset);
            wellPiece.setTextureRect(
                    sf::IntRect(tetrominoPiece[row][column] * width, 0, width, height));

            target.draw(wellPiece);
        }
    }
}

void NextPieceSection::clear() {
    for (unsigned int row = 0; row < ROWS; row++) {
        for (unsigned int column = 0; column < COLUMNS; column++) {
            tetrominoPiece[row][column] = BlockType::NONE;
        }
    }
}

void NextPieceSection::setXOffset(const unsigned int &xOffset) {
    NextPieceSection::xOffset = xOffset;
}

void NextPieceSection::setYOffset(const unsigned int &yOffset) {
    NextPieceSection::yOffset = yOffset;
}
