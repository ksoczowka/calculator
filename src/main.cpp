#include <SFML/Graphics.hpp>
#include <vector>

void centerOfWindow(sf::RenderWindow&);

const constexpr int WindowH = 600;
const constexpr int WindowW = 900;


int main()
{
    sf::RenderWindow window(sf::VideoMode(WindowW, WindowH), "Calculator", sf::Style::Titlebar | sf::Style::Close);
    centerOfWindow(window);

    sf::RectangleShape line1(sf::Vector2f(WindowW - 10, 2));
    line1.setFillColor(sf::Color::White);
    line1.setPosition(sf::Vector2f(5, WindowH/5));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear();
        window.draw(line1);
        window.display();
    }

    return 0;
}

void centerOfWindow(sf::RenderWindow& window){
    auto desktop = sf::VideoMode::getDesktopMode();
    sf::Vector2i mb = {int(desktop.width/2 - window.getSize().x/2),int(desktop.height/2 - window.getSize().y/2)};
    window.setPosition(mb);
}