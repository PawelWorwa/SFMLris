#include "Statistics.hpp"

const std::string Statistics::FONT_PATH =  "./media/tetrisFont.ttf";
const std::string Statistics::TITLE_TEXT = "SFMLris";
const std::string Statistics::NEXT_TEXT  = "Next: ";
const std::string Statistics::LEVEL_TEXT = "Level: ";
const std::string Statistics::LINES_TEXT = "Lines: ";
const std::string Statistics::SCORE_TEXT = "Score: ";

Statistics::Statistics() {
    font.loadFromFile(FONT_PATH);
    reset();
    prepareTexts();
    update();
}

void Statistics::addScore(const unsigned int &scoreToAdd) {
    score += scoreToAdd;
}

void Statistics::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(titleText);
    target.draw(nextBlockText);
    target.draw(levelText);
    target.draw(linesText);
    target.draw(scoreText);
}

sf::Text Statistics::genericText() {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(FONT_SIZE);
    text.setFillColor(sf::Color::White);

    return text;
}

void Statistics::update() {
    levelText.setString(
            LEVEL_TEXT + std::to_string(level));

    linesText.setString(
            LINES_TEXT + std::to_string(lines));

    scoreText.setString(
            SCORE_TEXT + std::to_string(score));
}

void Statistics::prepareTitleText() {
    titleText = genericText();
    titleText.setString(TITLE_TEXT);
    titleText.setCharacterSize(1.5d * FONT_SIZE);
    titleText.setPosition(WIDTH_PIXEL_OFFSET, TITLE_TOP_PIXEL_OFFSET);
}

void Statistics::prepareNextBlockText() {
    nextBlockText = genericText();
    nextBlockText.setString(NEXT_TEXT);
    nextBlockText.setPosition(WIDTH_PIXEL_OFFSET,
                              titleText.getPosition().y + HEIGHT_PIXEL_OFFSET * 1.5d);
}

void Statistics::prepareLevelText() {
    levelText = genericText();
    levelText.setPosition(WIDTH_PIXEL_OFFSET,
                          nextBlockText.getPosition().y + HEIGHT_PIXEL_OFFSET);
}

void Statistics::prepareLinesText() {
    linesText = genericText();
    linesText.setPosition(WIDTH_PIXEL_OFFSET,
                          levelText.getPosition().y + HEIGHT_PIXEL_OFFSET);
}

void Statistics::prepareScoreText() {
    scoreText = genericText();
    scoreText.setPosition(WIDTH_PIXEL_OFFSET,
                          linesText.getPosition().y + HEIGHT_PIXEL_OFFSET);
}

void Statistics::prepareTexts() {
    prepareTitleText();
    prepareNextBlockText();
    prepareLevelText();
    prepareLinesText();
    prepareScoreText();
}

void Statistics::addLines(const unsigned int &linesToAdd) {
    lines += linesToAdd;
}

const unsigned int Statistics::getNextBlockOffsetX() {
    return static_cast<const unsigned int>
    (nextBlockText.getPosition().x + nextBlockText.getGlobalBounds().width);
}

const unsigned int Statistics::getNextBlockOffsetY() {
    return static_cast<const unsigned int>(nextBlockText.getPosition().y);
}

void Statistics::reset() {
    level = 0;
    lines = 0;
    score = 0;
}

void Statistics::levelUp() {
    level++;
}
