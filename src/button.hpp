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
    Button(sf::Vector2f, std::string);

    sf::RectangleShape getShape();
<<<<<<< HEAD
    sf::Text getTextt();

=======
    sf::Text getText();
    void render(sf::RenderTarget*);
    std::string update(sf::Mouse, sf::Window*);
>>>>>>> d88aaf9653503c093985389d5740353c0aa69914
private:
    bool clicked_ = false;
    buttonStatus status_;
    sf::Font font_;
    std::string value_;
    sf::RectangleShape shape_;
    sf::Text text_ {};
};