#include "main.hpp"
#include "button.hpp"

#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WindowW, WindowH), "Calculator", sf::Style::Titlebar | sf::Style::Close);
    
    centerOfWindow(window);


    Button button = Button(sf::Vector2f(40, 40), "1");
    Button buttonCan = Button(sf::Vector2f(100, 40), "Can");

    line1.setFillColor(uiCol);
    line1.setPosition(sf::Vector2f(5, WindowH/5));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
            operation += button.update(cursor, &window);
            for()

            std::cerr << operation << '\n';
        }

        window.clear(backCol);
        window.draw(line1);
<<<<<<< HEAD
        window.draw(button.getShape());
        window.draw(button.getTextt());
=======
        button.render(&window);
        buttonCan.render(&window);
>>>>>>> d88aaf9653503c093985389d5740353c0aa69914
        window.display();
    }

    return 0;
}

void centerOfWindow(sf::RenderWindow& window){
    auto desktop = sf::VideoMode::getDesktopMode();
    sf::Vector2i mb = {int(desktop.width/2 - window.getSize().x/2),int(desktop.height/2 - window.getSize().y/2)};
    window.setPosition(mb);
}