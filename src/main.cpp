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
    buttons[0] = Button(sf::Vector2f(40, 200), "0");
    buttons[1] = Button(sf::Vector2f(100, 200), "1");
    buttons[2] = Button(sf::Vector2f(160, 200), "Can");
    buttons[3] = Button(sf::Vector2f(220, 200), "Del");
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
