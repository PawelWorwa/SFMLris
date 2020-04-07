#include "Well.hpp"

Well::Well(Texture &texture) : texture(texture) {
    clear();

    const sf::Texture &blocksTexture = texture.getBlocksTexture();
    renderedTexture.create(blocksTexture.getSize().x / texture.getBlocksInTexture() * ROWS,
                           blocksTexture.getSize().y * COLUMNS);
}

void Well::refresh() {
    renderedTexture.clear();
    drawPiecesToRenderTexture();
    renderedTexture.display();
}

void Well::setPiece(const int &row, const int &column, const BlockType &blockType) {
    blocks[row][column] = blockType;
}

void Well::clear() {
    for (unsigned int row = 0; row < ROWS; row++) {
        for (unsigned int column = 0; column < COLUMNS; column++) {
            blocks[row][column] = BlockType::NONE;
        }
    }
}

void Well::drawPiecesToRenderTexture() {
    const sf::Texture &blocksTexture = texture.getBlocksTexture();
    unsigned int width = blocksTexture.getSize().x / texture.getBlocksInTexture();
    unsigned int height = blocksTexture.getSize().y;

    for (unsigned int row = 0; row < ROWS; row++) {
        for (unsigned int column = FIRST_VISIBLE_COLUMN; column < COLUMNS; column++) {
            sf::Sprite wellPiece(blocksTexture);
            wellPiece.setPosition(width * row, height * (column - FIRST_VISIBLE_COLUMN));
            wellPiece.setTextureRect(
                    sf::IntRect(blocks[row][column] * width, 0, width, height));

            renderedTexture.draw(wellPiece);
        }
    }
}

void Well::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Sprite wellSprite(renderedTexture.getTexture());
    wellSprite.setPosition(PIXELS_OFFSET_FROM_BORDERS, PIXELS_OFFSET_FROM_BORDERS);
    target.draw(wellSprite);
}

bool Well::isPositionOccupied(const int &row, const int &column) {
    return blocks[row][column] != BlockType::NONE;
}

unsigned int Well::clearLinesAndMoveRestDown() {
    unsigned int clearedLines = 0;
    for (unsigned int column = COLUMNS - 1; column >= FIRST_VISIBLE_COLUMN; column--) {
        while (isLine(column)) {
            for (unsigned int tmpColumn = column; tmpColumn >= FIRST_VISIBLE_COLUMN; tmpColumn--) {
                for (unsigned int row = 0; row < ROWS; row++) {
                    blocks[row][tmpColumn] = blocks[row][tmpColumn - 1];
                }
            }

            clearedLines++;
        }
    }

    return clearedLines;
}

bool Well::isLine(const unsigned int &column) {
    unsigned int notEmptyRows = 0;
    for (unsigned int row = 0; row < ROWS; row++) {
        if (blocks[row][column] != BlockType::NONE) {
            notEmptyRows++;
        }
    }

    return (notEmptyRows == ROWS);
}

const unsigned int Well::getRows() {
    return ROWS;
}

const unsigned int Well::getColumns() {
    return COLUMNS;
}
