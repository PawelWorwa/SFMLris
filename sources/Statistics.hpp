#ifndef SFMLRIS_STATISTICS_HPP
#define SFMLRIS_STATISTICS_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>

class Statistics : public sf::Drawable {
    public:
        Statistics();

        void levelUp();
        void addLines(const unsigned int &linesToAdd);
        void addScore(const unsigned int &scoreToAdd);
        void update();

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        const unsigned int getNextBlockOffsetX();
        const unsigned int getNextBlockOffsetY();

        void reset();

    private:
        static const std::string FONT_PATH;
        static const std::string TITLE_TEXT;
        static const std::string NEXT_TEXT;
        static const std::string LEVEL_TEXT;
        static const std::string LINES_TEXT;
        static const std::string SCORE_TEXT;

        static const unsigned int FONT_SIZE = 50;
        static const unsigned int TITLE_TOP_PIXEL_OFFSET = 25;
        static const unsigned int WIDTH_PIXEL_OFFSET = 400;
        static const unsigned int HEIGHT_PIXEL_OFFSET = 100;

        unsigned int level;
        unsigned int lines;
        unsigned int score;

        sf::Font font;
        sf::Text nextBlockText;
        sf::Text titleText;
        sf::Text levelText;
        sf::Text linesText;
        sf::Text scoreText;

        void prepareTitleText();
        void prepareNextBlockText();
        void prepareLevelText();
        void prepareLinesText();
        void prepareScoreText();
        void prepareTexts();
        sf::Text genericText();
};

#endif //SFMLRIS_STATISTICS_HPP
