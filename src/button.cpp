#include "button.hpp"


Button::Button(sf::Vector2f pos, std::string value) {
    shape_ = sf::RectangleShape(sf::Vector2f(40, 40));
    shape_.setFillColor(sf::Color::Magenta);
    shape_.setPosition(pos);

    value_ = value;

    sf::Font font;
    font.loadFromFile("font/font.ttf");
    text_.setCharacterSize(20);
    text_.setFont(font);
    text_.setFillColor(sf::Color(180, 180, 180));
    text_.setString(value_);
    text_.setPosition(pos);
}
sf::RectangleShape Button::getShape() {
    return shape_;
}
sf::Text Button::getTextt() {
    return text_;
}