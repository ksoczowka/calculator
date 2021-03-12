#pragma once

#include <SFML/Graphics.hpp>
#include <string>

enum class buttonStatus {
    IDLE,
    HOVER,
    ACTIVE,
};

class Button {
public:
    Button(){};
    Button(sf::Vector2f, std::string);

    Button operator=(Button&);

    void render(sf::RenderTarget*);
    std::string update(sf::Mouse, sf::Window*);

private:
    bool clicked_ = false;
    sf::Font font_;
    buttonStatus status_;
    std::string value_;
    sf::RectangleShape shape_;
    sf::Text text_ ;
};
