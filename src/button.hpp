#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    Button(sf::Vector2f, std::string);

    sf::RectangleShape getShape();
    sf::Text getText();
    void render(sf::RenderTarget*);
private:
    sf::Font font_;
    std::string value_;
    sf::RectangleShape shape_;
    sf::Text text_;
};