#ifndef SFMLRIS_BLOCK_HPP
#define SFMLRIS_BLOCK_HPP

#include <vector>

#include "BlockType.hpp"
#include "BlockPiece.hpp"

// https://gamedev.stackexchange.com/questions/17974/how-to-rotate-blocks-in-tetris
class Block {
     public:
        Block();
        explicit Block(BlockType type);

        BlockType getBlockType() const;
        const std::vector< BlockPiece > &getPieces() const;

        void setPivotPiece(const unsigned int &pivotPiece);
        void setPieces(
                const BlockPiece &piece1,
                const BlockPiece &piece2,
                const BlockPiece &piece3,
                const BlockPiece &piece4);

        void genericMovement(const int &xOffset, const int &yOffset);
        void moveDown();
        void moveLeft();
        void moveRight();
        void rotate();

        bool isInRow(const unsigned int &row);

    private:
        unsigned int pivotPiece = 0;

        std::vector< BlockPiece > pieces;
        BlockType blockType;
};

#endif //SFMLRIS_BLOCK_HPP