#include "BlockCreator.hpp"

BlockCreator::BlockCreator() {
    fillTetrominoMap();
}

Block BlockCreator::create(const BlockType &blockType) {
    return blocks.at(blockType);
}

Block BlockCreator::createI() {
    Block block(BlockType::I);
    block.setPivotPiece(1);
    block.setPieces(
            BlockPiece(0, 1),
            BlockPiece(1, 1),
            BlockPiece(2, 1),
            BlockPiece(3, 1));

    return block;
}

Block BlockCreator::createJ() {
    Block block(BlockType::J);
    block.setPivotPiece(2);
    block.setPieces(
            BlockPiece(0, 0),
            BlockPiece(0, 1),
            BlockPiece(1, 1),
            BlockPiece(2, 1));

    return block;
}

Block BlockCreator::createL() {
    Block block(BlockType::L);
    block.setPivotPiece(1);
    block.setPieces(
            BlockPiece(0, 1),
            BlockPiece(1, 1),
            BlockPiece(2, 1),
            BlockPiece(2, 0));

    return block;
}

Block BlockCreator::createO() {
    Block block(BlockType::O);
    block.setPivotPiece(0);
    block.setPieces(
            BlockPiece(1, 0),
            BlockPiece(2, 0),
            BlockPiece(1, 1),
            BlockPiece(2, 1));

    return block;
}

Block BlockCreator::createS() {
    Block block(BlockType::S);
    block.setPivotPiece(1);
    block.setPieces(
            BlockPiece(0, 1),
            BlockPiece(1, 1),
            BlockPiece(1, 0),
            BlockPiece(2, 0));

    return block;
}

Block BlockCreator::createT() {
    Block block(BlockType::T);
    block.setPivotPiece(1);
    block.setPieces(
            BlockPiece(0, 1),
            BlockPiece(1, 1),
            BlockPiece(1, 0),
            BlockPiece(2, 1));

    return block;
}

Block BlockCreator::createZ() {
    Block block(BlockType::Z);
    block.setPivotPiece(2);
    block.setPieces(
            BlockPiece(0, 0),
            BlockPiece(1, 0),
            BlockPiece(1, 1),
            BlockPiece(2, 1));

    return block;
}

void BlockCreator::fillTetrominoMap() {
    blocks.insert({BlockType::I, createI()});
    blocks.insert({BlockType::J, createJ()});
    blocks.insert({BlockType::L, createL()});
    blocks.insert({BlockType::O, createO()});
    blocks.insert({BlockType::S, createS()});
    blocks.insert({BlockType::T, createT()});
    blocks.insert({BlockType::Z, createZ()});
}