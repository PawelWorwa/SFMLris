#ifndef SFMLRIS_WELL_HPP
#define SFMLRIS_WELL_HPP

#include <memory>
#include <vector>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "BlockType.hpp"
#include "Texture.hpp"

class Well : public sf::Drawable {
    public:
        explicit Well(Texture &texture);

        unsigned int clearLinesAndMoveRestDown();
        bool isPositionOccupied(const int &row, const int &column);

        void clear();
        void refresh();
        void setPiece(const int &row, const int &column, const BlockType &blockType);

        const unsigned int getRows();
        const unsigned int getColumns();

    private:
        static const unsigned int ROWS = 10;
        static const unsigned int COLUMNS = 22;
        static const unsigned int FIRST_VISIBLE_COLUMN = 2;
        static const unsigned int PIXELS_OFFSET_FROM_BORDERS = 50;

        BlockType blocks[ROWS][COLUMNS];
        Texture &texture;
        sf::RenderTexture renderedTexture;

        bool isLine(const unsigned int &column);
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
        void drawPiecesToRenderTexture();

};

#endif //SFMLRIS_WELL_HPP
