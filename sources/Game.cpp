#include "Game.hpp"

const std::string Game::GAME_TITLE                 = "SFMLris";
const std::string Game::MUSIC_THEME_PATH           = "./media/twister.ogg";
const std::string Game::ROTATE_SOUND_EFFECT_PATH   = "./media/rotate.ogg";
const std::string Game::BOOM_SOUND_EFFECT_PATH     = "./media/boom.ogg";
const std::string Game::END_SOUND_EFFECT_PATH      = "./media/end.ogg";
const std::string Game::HIT_SOUND_EFFECT_PATH      = "./media/hit.ogg";
const std::string Game::LEVEL_UP_SOUND_EFFECT_PATH = "./media/levelup.ogg";
const std::string Game::MOVE_SOUND_EFFECT_PATH     = "./media/move.ogg";

Game::Game() :
        boomSound(BOOM_SOUND_EFFECT_PATH),
        gameOverSound(END_SOUND_EFFECT_PATH),
        hitSound(HIT_SOUND_EFFECT_PATH),
        levelUpSound(LEVEL_UP_SOUND_EFFECT_PATH),
        moveSound(MOVE_SOUND_EFFECT_PATH),
        nextPieceSection(texture),
        rotateSound(ROTATE_SOUND_EFFECT_PATH),
        well(texture),
        window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE) {

    window.setFramerateLimit(FPS);
    theme.openFromFile(MUSIC_THEME_PATH);
    theme.setVolume(25.f); // music is very loud...
    theme.setLoop(true);

    block = randomBlock();
    defaultTetrominoState();

    nextPieceSection.addTetromino(nextBlock);
    nextPieceSection.setXOffset(statistics.getNextBlockOffsetX());
    nextPieceSection.setYOffset(statistics.getNextBlockOffsetY());
}

Block Game::randomBlock() {
    return blockCreator.create(
            static_cast<BlockType>((rand() % NUMBER_OF_TETROMINOS) + 1));
}

void Game::loop() {
    theme.play();

    while (window.isOpen()) {
        processEvents();
        update();
        draw();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();

        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::M) {
                if (theme.getStatus() == sf::Music::Status::Playing) {
                    theme.pause();

                } else {
                    theme.play();
                }
            }

            if (event.key.code == sf::Keyboard::P) {
                pause = !pause;
            }

            if (!gameOver && !pause && isBlockVisibleOnWell()) {
                clearCurrentTerominoOnWell();
                processPlayerMovement(event);
            }

            if (gameOver) {
                reset();
            }
        }
    }
}

void Game::draw() {
    window.clear(sf::Color::Black);

    window.draw(well);
    window.draw(statistics);
    window.draw(nextPieceSection);

    window.display();
}

void Game::update() {
    if (gameOver) {
        gameOverSound.playOnce();

    } else {
        if (!pause) {
            clearCurrentTerominoOnWell();

            bool isNextMoveFinal = false;
            if (clock.getElapsedTime().asMilliseconds() >= gameSpeed) {
                Block ghost = block;
                ghost.moveDown();
                isNextMoveFinal = (isCollisionWithBlocks(ghost) || isCollisionWithBottom(ghost));
                if (!isNextMoveFinal) {
                    block.moveDown();
                    clock.restart();
                }
            }

            updateCurrentTetrominoOnWell();
            if (isNextMoveFinal) {
                hitSound.play();
                if (isCollisionAfterFirstMove()) {
                    gameOver = true;
                }

                block = nextBlock;
                defaultTetrominoState();

                clearedLinesDuringLevel += clearAndCountClearedLines();
                if (isLevelUp()) {
                    levelUp();
                }

                statistics.update();
                nextPieceSection.clear();
                nextPieceSection.addTetromino(nextBlock);
            }

            well.refresh();
        }
    }
}

void Game::processPlayerMovement(sf::Event event) {
    switch (event.key.code) {
        case sf::Keyboard::Up :
            blockRotate();
            break;

        case sf::Keyboard::Left :
            blockMoveLeft();
            break;

        case sf::Keyboard::Right :
            blockMoveRight();
            break;

        case sf::Keyboard::Down :
            blockMoveDown();
            break;

        default :
            break;
    }
}

void Game::updateCurrentTetrominoOnWell() {
    for (auto piece : block.getPieces()) {
        well.setPiece(piece.getXPos(), piece.getYPos(), block.getBlockType());
    }
}

void Game::clearCurrentTerominoOnWell() {
    for (auto piece : block.getPieces()) {
        well.setPiece(piece.getXPos(), piece.getYPos(), BlockType::NONE);
    }
}

void Game::defaultTetrominoState() {
    block.genericMovement(DEFAULT_TETROMINO_POSITION_ON_WELL, 0);
    nextBlock = randomBlock();
}

void Game::reset() {
    gameOver = false;

    well.clear();
    nextPieceSection.clear();

    block = randomBlock();
    defaultTetrominoState();

    nextPieceSection.addTetromino(nextBlock);
    statistics.reset();
}

bool Game::isCollisionAfterFirstMove() {
    return (block.isInRow(0) || block.isInRow(1));
}

bool Game::isLevelUp() {
    return clearedLinesDuringLevel >= REQUIRED_LINES_FOR_LEVEL_UP;
}

void Game::increaseSpeed() {
    if (gameSpeed >= MAX_SPEED_MS + LEVEL_UP_SPEED_INCREASE_MS) {
        gameSpeed -= LEVEL_UP_SPEED_INCREASE_MS;
    }
}

void Game::levelUp() {
    levelUpSound.play();
    increaseSpeed();
    statistics.levelUp();
    clearedLinesDuringLevel = 0;
}

unsigned int Game::clearAndCountClearedLines() {
    unsigned int clearedLines = well.clearLinesAndMoveRestDown();
    if (clearedLines > 0) {
        boomSound.play();
        statistics.addLines(clearedLines);
        statistics.addScore(clearedLines * clearedLines);

        return clearedLines;
    }

    return 0;
}


bool Game::isCollisionWithLeftBoundary(const Block &block) {
    for (auto piece : block.getPieces()) {
        if (piece.getXPos() < 0) {
            return true;
        }
    }

    return false;
}

bool Game::isCollisionWithRightBoundary(const Block &block) {
    for (auto piece : block.getPieces()) {
        if (piece.getXPos() > well.getRows() - 1) {
            return true;
        }
    }

    return false;
}

bool Game::isCollisionWithBottom(const Block &block) {
    for (auto piece : block.getPieces()) {
        if (piece.getYPos() >= well.getColumns()) {
            return true;
        }
    }

    return false;
}

bool Game::isCollisionWithBlocks(const Block &block) {
    for (auto piece : block.getPieces()) {
        if (well.isPositionOccupied(piece.getXPos(), piece.getYPos())) {
            return true;
        }
    }

    return false;
}

void Game::blockRotate() {
    Block ghostBlock = block;
    ghostBlock.rotate();
    if (!isCollisionWithLeftBoundary(ghostBlock) &&
        !isCollisionWithRightBoundary(ghostBlock) &&
        !isCollisionWithBottom(ghostBlock) &&
        !isCollisionWithBlocks(ghostBlock)) {

        rotateSound.play();
        block.rotate();
    }
}

void Game::blockMoveDown() {
    Block ghostBlock = block;
    ghostBlock.moveDown();
    if (!isCollisionWithBottom(ghostBlock) && !isCollisionWithBlocks(ghostBlock)) {
        moveSound.play();
        block.moveDown();
    }
}

void Game::blockMoveLeft() {
    Block ghostBlock = block;
    ghostBlock.moveLeft();
    if (!isCollisionWithLeftBoundary(ghostBlock) && !isCollisionWithBlocks(ghostBlock)) {
        moveSound.play();
        block.moveLeft();
    }
}

void Game::blockMoveRight() {
    Block ghostBlock = block;
    ghostBlock.moveRight();
    if (!isCollisionWithRightBoundary(ghostBlock) && !isCollisionWithBlocks(ghostBlock)) {
        moveSound.play();
        block.moveRight();
    }
}

bool Game::isBlockVisibleOnWell() {
    return (!block.isInRow(0) && !block.isInRow(1));
}
