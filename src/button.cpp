#include "button.hpp"


Button::Button(sf::Vector2f pos, std::string value) {
    shape_ = sf::RectangleShape(sf::Vector2f(40, 40));
    shape_.setFillColor(sf::Color::Magenta);
    shape_.setPosition(pos);

    value_ = value;

    font_.loadFromFile("font/font.ttf");
    text_.setCharacterSize(20);
<<<<<<< HEAD
    text_.setFont(font);
    text_.setFillColor(sf::Color(180, 180, 180));
=======
    text_.setFont(font_);
    text_.setFillColor(sf::Color::White);
>>>>>>> d88aaf9653503c093985389d5740353c0aa69914
    text_.setString(value_);
    text_.setPosition(pos.x + shape_.getGlobalBounds().width/2. - text_.getGlobalBounds().width,
                      pos.y + shape_.getGlobalBounds().height/2. - text_.getGlobalBounds().height);
}
sf::RectangleShape Button::getShape() {
    return shape_;
}
sf::Text Button::getTextt() {
    return text_;
}
void Button::render(sf::RenderTarget* target) {
    target->draw(shape_);
    target->draw(text_);
}
std::string Button::update(sf::Mouse cursor, sf::Window* window) {
    status_ = buttonStatus::IDLE;
    if(shape_.getGlobalBounds().contains(sf::Vector2f(cursor.getPosition(*window)))) {
        status_ = buttonStatus::HOVER;
        if(cursor.isButtonPressed(sf::Mouse::Button::Left)) {
            status_ = buttonStatus::ACTIVE;
        }
    }
    switch(status_) {
        case buttonStatus::IDLE:
            clicked_ = false;
            shape_.setFillColor(sf::Color::Green);
            break;
        case buttonStatus::HOVER:
            clicked_ = false;
            shape_.setFillColor(sf::Color::Yellow);
            break;
        case buttonStatus::ACTIVE:
            shape_.setFillColor(sf::Color::Red);
            if(!clicked_) {
                clicked_ = true;
                return value_;
            }
            break;
    }
    return "";
}
