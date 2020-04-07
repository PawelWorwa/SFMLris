#include "Block.hpp"

Block::Block() :
        blockType(BlockType::NONE) {
}

Block::Block(BlockType tetrominoType) :
        blockType(tetrominoType) {
};

BlockType Block::getBlockType() const {
    return blockType;
}

const std::vector< BlockPiece > &Block::getPieces() const {
    return pieces;
}

void Block::setPivotPiece(const unsigned int &pivotPiece) {
    Block::pivotPiece = pivotPiece;
}

void Block::rotate() {
    if (BlockType::O == blockType) {
        return;
    }

    int pivotX = pieces.at(pivotPiece).getXPos();
    int pivotY = pieces.at(pivotPiece).getYPos();
    for (auto &piece : pieces) {
        int xPos = piece.getXPos();
        int yPos = piece.getYPos();
        piece.setXPos(yPos + pivotX - pivotY);
        piece.setYPos(pivotX + pivotY - xPos);
    }
}

void Block::setPieces(const BlockPiece &piece1, const BlockPiece &piece2, const BlockPiece &piece3, const BlockPiece &piece4) {
    pieces.emplace_back(piece1.getXPos(), piece1.getYPos());
    pieces.emplace_back(piece2.getXPos(), piece2.getYPos());
    pieces.emplace_back(piece3.getXPos(), piece3.getYPos());
    pieces.emplace_back(piece4.getXPos(), piece4.getYPos());
}

void Block::moveDown() {
    genericMovement(0, 1);
}

void Block::moveLeft() {
    genericMovement(-1, 0);
}

void Block::moveRight() {
    genericMovement(1, 0);
}

void Block::genericMovement(const int &xOffset, const int &yOffset) {
    for (auto &piece : pieces) {
        piece.setXPos(piece.getXPos() + xOffset);
        piece.setYPos(piece.getYPos() + yOffset);
    }
}

bool Block::isInRow(const unsigned int &row) {
    for (auto &piece : pieces) {
        if (piece.getYPos() == row) {
            return true;
        }
    }

    return false;
}
