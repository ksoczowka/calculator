#pragma once

#include <SFML/Graphics.hpp>
#include <string>

enum class buttonStatus {
    IDLE,
    HOVER,
    ACTIVE
};

class Button {
public:
    Button(sf::Vector2f, std::string);

    sf::RectangleShape getShape();
    sf::Text getText();
    void render(sf::RenderTarget*);
    void update(sf::Mouse, sf::Window*);
private:
    buttonStatus status_;
    sf::Font font_;
    std::string value_;
    sf::RectangleShape shape_;
    sf::Text text_;
};