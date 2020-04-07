#include "sources/Game.hpp"

int main() {
    srand((unsigned) time(nullptr));

    Game game;
    game.loop();

    return EXIT_SUCCESS;
}