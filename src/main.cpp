#include "main.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WindowW, WindowH), "Calculator", sf::Style::Titlebar | sf::Style::Close);
    
    centerOfWindow(window);

    line1.setFillColor(uiCol);
    line1.setPosition(sf::Vector2f(5, WindowH/5));

    font.loadFromFile("font/font.ttf");
    output.setFont(font);
    output.setFillColor(sf::Color::Magenta);
    output.setPosition(sf::Vector2f(10, 10));
    output.setString("0");
    output.setCharacterSize(50);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            
            for(auto& it: buttons){
                std::string buff {};
                buff = it.update(cursor, &window);
                if(buff == "Can"){
                    operation = "0";
                } else if(buff == "Del" && operation != ""){
                    operation.pop_back();
                    if(operation == "") {
                        operation = "0";
                    }
                } else if(buff == "0" && operation == "0"){
                    operation += "";
                } else if(buff != ""){
                    if(operation == "0"){
                        operation = "";
                    }
                    operation += buff;
                }
                output.setString(operation);

            }
        }
        renderWindow(&window);
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
    buttons[0] = Button(sf::Vector2f(500, 500), "0");
    buttons[1] = Button(sf::Vector2f(100, 200), "1");
    buttons[2] = Button(sf::Vector2f(100, 200), "2");
    buttons[3] = Button(sf::Vector2f(100, 200), "3");
    buttons[4] = Button(sf::Vector2f(100, 200), "4");
    buttons[5] = Button(sf::Vector2f(100, 200), "5");
    buttons[6] = Button(sf::Vector2f(100, 200), "6");
    buttons[7] = Button(sf::Vector2f(100, 200), "7");
    buttons[8] = Button(sf::Vector2f(100, 200), "8");
    buttons[9] = Button(sf::Vector2f(100, 200), "9");

    buttons[10] = Button(sf::Vector2f(160, 200), "Can");
    buttons[11] = Button(sf::Vector2f(220, 200), "Del");
    return buttons;
}
void renderWindow(sf::RenderTarget* window) {
    window->clear(backCol);
    window->draw(line1);
    window->draw(output);
    for(auto& it: buttons){
        it.render(window);
    }
}
