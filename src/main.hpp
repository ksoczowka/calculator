#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <array>

#include "button.hpp"

const constexpr int WindowH = 600;
const constexpr int WindowW = 900;

const size_t buttonCount = 4;

sf::Color backCol = sf::Color(48, 48, 48);
sf::Color uiCol = sf::Color(200, 200, 200);
sf::Color specialUiColor = sf::Color(255, 69, 0);
sf::Color textColor = sf::Color(180, 180, 180);
sf::Color buttonColorIdle = sf::Color::Green;
sf::Color buttonColorHover = sf::Color::Yellow;
sf::Color buttonColorActive = sf::Color::Red;

sf::RectangleShape line1(sf::Vector2f(WindowW - 10, 2));

sf::Mouse cursor;

std::string operation = "0";
sf::Text output;
sf::Font font;

void centerOfWindow(sf::RenderWindow&);
void renderWindow(sf::RenderTarget*);

std::array<Button, buttonCount> createButtons();

std::array<Button, buttonCount> buttons = createButtons();
