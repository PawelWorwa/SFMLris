cmake_minimum_required(VERSION 3.9)
project(SFMLris VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(SFMLris
        main.cpp
        sources/BlockType.hpp
        sources/BlockPiece.cpp
        sources/BlockPiece.hpp
        sources/Block.cpp
        sources/Block.hpp
        sources/BlockCreator.cpp
        sources/BlockCreator.hpp
        sources/Well.cpp
        sources/Well.hpp
        sources/Game.cpp
        sources/Game.hpp
        sources/NextPieceSection.cpp
        sources/NextPieceSection.hpp
        sources/Texture.cpp sources/Texture.hpp
        sources/Statistics.cpp
        sources/Statistics.hpp
        sources/SoundEffect.hpp
        sources/SoundEffect.cpp)

set(SFML_DIR "${SFML_PATH}")

find_package(SFML 2.5 COMPONENTS graphics audio)

target_link_libraries(SFMLris sfml-graphics sfml-audio)