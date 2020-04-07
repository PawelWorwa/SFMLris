#ifndef SFMLRIS_GAME_HPP
#define SFMLRIS_GAME_HPP

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "BlockCreator.hpp"
#include "NextPieceSection.hpp"
#include "Statistics.hpp"
#include "SoundEffect.hpp"
#include "Well.hpp"

class Game {
    public:
        Game();

        void loop();

    private:
        static const std::string GAME_TITLE;
        static const std::string MUSIC_THEME_PATH;
        static const std::string ROTATE_SOUND_EFFECT_PATH;
        static const std::string BOOM_SOUND_EFFECT_PATH;
        static const std::string END_SOUND_EFFECT_PATH;
        static const std::string HIT_SOUND_EFFECT_PATH;
        static const std::string LEVEL_UP_SOUND_EFFECT_PATH;
        static const std::string MOVE_SOUND_EFFECT_PATH;

        static const unsigned int WINDOW_WIDTH = 800;
        static const unsigned int WINDOW_HEIGHT = 600;
        static const unsigned int FPS = 30;

        static const unsigned int DEFAULT_TURN_DURATION_MS = 500;
        static const unsigned int MAX_SPEED_MS = 100;
        static const unsigned int LEVEL_UP_SPEED_INCREASE_MS = 25;
        static const unsigned int DEFAULT_TETROMINO_POSITION_ON_WELL = 3;
        static const unsigned int NUMBER_OF_TETROMINOS = 6;
        static const unsigned int REQUIRED_LINES_FOR_LEVEL_UP = 10;

        bool gameOver = false;
        bool pause = false;
        float gameSpeed = DEFAULT_TURN_DURATION_MS;
        unsigned int clearedLinesDuringLevel = 0;

        sf::Music theme;
        SoundEffect boomSound;
        SoundEffect gameOverSound;
        SoundEffect hitSound;
        SoundEffect levelUpSound;
        SoundEffect moveSound;
        SoundEffect rotateSound;

        Texture texture;
        Well well;
        NextPieceSection nextPieceSection;
        Statistics statistics;
        BlockCreator blockCreator;
        Block block;
        Block nextBlock;

        sf::RenderWindow window;
        sf::Clock clock;

        unsigned int clearAndCountClearedLines();
        Block randomBlock();

        void draw();
        void processEvents();
        void processPlayerMovement(sf::Event event);
        void update();

        void clearCurrentTerominoOnWell();
        void defaultTetrominoState();
        void increaseSpeed();
        void levelUp();
        void reset();
        void updateCurrentTetrominoOnWell();

        bool isCollisionAfterFirstMove();
        bool isCollisionWithLeftBoundary(const Block &block);
        bool isCollisionWithRightBoundary(const Block &block);
        bool isCollisionWithBottom(const Block &block);
        bool isCollisionWithBlocks(const Block &block);
        bool isBlockVisibleOnWell();
        bool isLevelUp();

        void blockRotate();
        void blockMoveDown();
        void blockMoveLeft();
        void blockMoveRight();
};

#endif //SFMLRIS_GAME_HPP
