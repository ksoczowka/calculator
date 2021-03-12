#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <array>

#include "button.hpp"

const constexpr int WindowH = 600;
const constexpr int WindowW = 900;


sf::Color backCol = sf::Color(48, 48, 48);
sf::Color uiCol = sf::Color(200, 200, 200);
sf::Color specialUiColor = sf::Color(255, 69, 0);
sf::Color textColor = sf::Color(180, 180, 180);

sf::RectangleShape line1(sf::Vector2f(WindowW - 10, 2));

sf::Mouse cursor;

std::string operation {};

void centerOfWindow(sf::RenderWindow&);
std::array<Button, 2> createButtons();

std::array<Button, 2> buttons = createButtons();
