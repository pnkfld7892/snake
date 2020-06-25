#include "snake.h"
#include <SFML/Window/Window.hpp>
#include <iostream>
#include <ostream>

int main(){
    std::cout <<"welcome to snake" << std::endl;
    sf::RenderWindow window(sf::VideoMode(400,400),"Snake!");

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
                    if(event.type ==sf::Event::Closed)
                        window.close();
                        }
        window.clear();
        window.display();
    }
}
