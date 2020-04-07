#ifndef SFMLRIS_NEXTPIECESECTION_HPP
#define SFMLRIS_NEXTPIECESECTION_HPP

#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "BlockPiece.hpp"
#include "BlockType.hpp"
#include "Block.hpp"
#include "Texture.hpp"

class NextPieceSection : public sf::Drawable {
    public:
        NextPieceSection(Texture &texture);

        void setXOffset(const unsigned int &xOffset);
        void setYOffset(const unsigned int &yOffset);

        void addTetromino(const Block &tetromino);
        void clear();
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        static const unsigned int ROWS = 4;
        static const unsigned int COLUMNS = 2;

        unsigned int xOffset = 0;
        unsigned int yOffset = 0;

        Texture &texture;
        BlockType tetrominoPiece[ROWS][COLUMNS];
};

#endif //SFMLRIS_NEXTPIECESECTION_HPP
