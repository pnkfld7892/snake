#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include <ostream>
#include "direction.h"
#include "snake.h"
#include "food.h"

int main(){
    std::cout <<"welcome to snake" << std::endl;
    sf::RenderWindow window(sf::VideoMode(400,400),"Snake!");

        Snake snake; 
        Food food(sf::Vector2f(150,220));
        snake.changeDirection(sf::Vector2f(1,0));
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
                  switch(event.type){  
                      case sf::Event::Closed:
                          window.close();
                          break;
                      case sf::Event::KeyPressed:
                          switch(event.key.code){
                              case sf::Keyboard::Up:
                                  snake.changeDirection(direction["Up"]);
                                    break;
                              case sf::Keyboard::Down:
                                  snake.changeDirection(direction["Down"]);
                                    break;
                              case sf::Keyboard::Left:
                                  snake.changeDirection(direction["Left"]);
                                    break;
                              case sf::Keyboard::Right:
                                  snake.changeDirection(direction["Right"]);
                                    break;
                              case sf::Keyboard::Escape:
                              case sf::Keyboard::Q:
                                  window.close();
                                  break;
                              default:
                                    break;
                          }
                          break;
                     default:
                          break;
                  }
        }
        
        window.clear(sf::Color(50,50,50));
        snake.update();
        if((snake.getSnakeHead().getPosition().y/2.0) + snake.getSnakeHead().getSize().x >= window.getSize().y)
        {
            snake.setHeadPosition('Y',0);
        }
        window.draw(food.getShape());
        window.draw(snake.getSnakeHead());
        window.display();
    }
}
