#include "BlockPiece.hpp"

BlockPiece::BlockPiece(const int &xPos, const int &yPos)
        : xPos(xPos),
          yPos(yPos) {
}

int BlockPiece::getXPos() const {
    return xPos;
}

int BlockPiece::getYPos() const {
    return yPos;
}

void BlockPiece::setXPos(const int &xPos) {
    BlockPiece::xPos = xPos;
}

void BlockPiece::setYPos(const int &yPos) {
    BlockPiece::yPos = yPos;
}
