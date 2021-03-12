#include "main.hpp"
#include <algorithm>
#include <iostream>

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

    std::sort(operators.begin(), operators.end());

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
                    first = "";
                    operatoR = "";
                    hasOperator = false;
                } 
                else if(buff == "Del" && operation != ""){
                    operation.pop_back();
                    if(operation == "") {
                        operation = "0";
                    }
                } 
                else if(isOperator(buff) && !hasOperator){
                    first = "";
                    first = operation;
                    operatoR = buff;
                    operation = "";
                    buff = "";
                    hasOperator = true;
                }
                else if(buff == "="){
                    resultFunc(first, operatoR, operation);
                    first = "";
                    operatoR = "";
                    hasOperator = false;
                }
                else if(buff == "0" && operation == "0"){
                    //do nothing
                }
                else if(buff != "" && !isOperator(buff)){
                    if(operation == "0"){
                        operation = "";
                    }
                    operation += buff;
                }
                output.setString(first + operatoR + operation);
                

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
    buttons[0] = Button(sf::Vector2f(655, 545), "0");
    buttons[1] = Button(sf::Vector2f(600, 490), "1");
    buttons[2] = Button(sf::Vector2f(655, 490), "2");
    buttons[3] = Button(sf::Vector2f(710, 490), "3");
    buttons[4] = Button(sf::Vector2f(600, 435), "4");
    buttons[5] = Button(sf::Vector2f(655, 435), "5");
    buttons[6] = Button(sf::Vector2f(710, 435), "6");
    buttons[7] = Button(sf::Vector2f(600, 380), "7");
    buttons[8] = Button(sf::Vector2f(655, 380), "8");
    buttons[9] = Button(sf::Vector2f(710, 380), "9");

    buttons[10] = Button(sf::Vector2f(600, 545), "Can");
    buttons[11] = Button(sf::Vector2f(710, 545), "Del");

    buttons[12] = Button(sf::Vector2f(765, 325), "+");
    buttons[13] = Button(sf::Vector2f(765, 380), "-");
    buttons[14] = Button(sf::Vector2f(765, 435), "*");
    buttons[15] = Button(sf::Vector2f(765, 490), "/");

    buttons[16] = Button(sf::Vector2f(655, 325), "(");
    buttons[17] = Button(sf::Vector2f(710, 325), ")");

    buttons[18] = Button(sf::Vector2f(765, 545), "=");
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
void resultFunc(std::string& first, std::string& op, std::string& secound) {
    if(op == "+"){
        operation = std::to_string(std::stoi(first) + std::stoi(secound));
    }
    else if(op == "-"){
        operation = std::to_string(std::stoi(first) - std::stoi(secound));
    }
    else if(op == "*"){
        operation = std::to_string(std::stoi(first) * std::stoi(secound));
    }
    else if(op == "/"){
        operation = std::to_string((std::stof(first) / std::stof(secound)));
    }
    else{}
    
}

