#include "main.hpp"


#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WindowW, WindowH), "Calculator", sf::Style::Titlebar | sf::Style::Close);
    
    centerOfWindow(window);

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
            
            for(auto& it: buttons){
                std::string buff {};
                buff = it.update(cursor, &window);
                if(buff == "Can"){
                    operation = "";
                } else if(buff == "Del"){
                    operation.pop_back();
                } else if(buff != ""){
                    operation += buff;
                }

            }
            std::cerr << operation << '\n';
        }

        window.clear(backCol);
        window.draw(line1);
        
        for(auto& it: buttons){
            it.render(&window);
        }
        window.display();
    }

    return 0;
}

void centerOfWindow(sf::RenderWindow& window){
    auto desktop = sf::VideoMode::getDesktopMode();
    sf::Vector2i mb = {int(desktop.width/2 - window.getSize().x/2),int(desktop.height/2 - window.getSize().y/2)};
    window.setPosition(mb);
}

std::array<Button, buttonCount> createButtons(){
    std::array<Button, buttonCount> buttons;
    buttons[0] = Button(sf::Vector2f(40, 40), "1");
    buttons[1] = Button(sf::Vector2f(100, 40), "Can");
    buttons[2] = Button(sf::Vector2f(160, 40), "Del");
    return buttons;
}