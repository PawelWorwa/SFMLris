#ifndef SFMLRIS_BLOCKCREATOR_HPP
#define SFMLRIS_BLOCKCREATOR_HPP

#include <functional>
#include <map>

#include "Block.hpp"

class BlockCreator {
    public:
        BlockCreator();

        Block create(const BlockType &blockType);

    private:
        std::map< BlockType, Block > blocks;

        void fillTetrominoMap();

        Block createI();
        Block createJ();
        Block createL();
        Block createO();
        Block createS();
        Block createT();
        Block createZ();
};

#endif //SFMLRIS_BLOCKCREATOR_HPP
