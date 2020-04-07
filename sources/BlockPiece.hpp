#ifndef SFMLRIS_BLOCKPIECE_HPP
#define SFMLRIS_BLOCKPIECE_HPP

class BlockPiece {
    public:
        BlockPiece(const int &xPos, const int &yPos);

        int getXPos() const;
        int getYPos() const;
        void setXPos(const int &xPos);
        void setYPos(const int &yPos);

    private:
        int xPos;
        int yPos;
};

#endif //SFMLRIS_BLOCKPIECE_HPP
