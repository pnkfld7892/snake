#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include <stdlib.h>
#include "direction.h"
#include "snake.h"
#include "food.h"

//checks snake against window bounds
//wraps around if off an edge
void checkBounds(sf::Vector2u windowSize, Snake* snake)
{
        
        if((snake->getSnakeHead().getPosition().y) + (snake->getSnakeHead().getSize().y/2) <= 0)
        {
            snake->setHeadPosition('Y', windowSize.y - snake->getSnakeHead().getSize().y);
        }
        
        if((snake->getSnakeHead().getPosition().y) + (snake->getSnakeHead().getSize().y/2) >= windowSize.y)
        {
            snake->setHeadPosition('Y',0);
        }
        
        if((snake->getSnakeHead().getPosition().x) + (snake->getSnakeHead().getSize().x/2) <= 0)
        {
            snake->setHeadPosition('X',windowSize.x - snake->getSnakeHead().getSize().x);
        }
        
        if((snake->getSnakeHead().getPosition().x) + (snake->getSnakeHead().getSize().x/2) >= windowSize.x)
        {
            snake->setHeadPosition('X',0);
        }
}


int main(){
    std::cout <<"welcome to snake" << std::endl;
    sf::RenderWindow window(sf::VideoMode(640,480),"Snake!");

    window.setFramerateLimit(60);
    
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
        checkBounds(window.getSize(), &snake);
        
        if(snake.getSnakeHead().getGlobalBounds().intersects(food.getShape().getGlobalBounds())){
            food.setPosition(sf::Vector2f(std::rand() % window.getSize().x + 1,std::rand() % window.getSize().y));
            snake.increaseSpeed();
            snake.grow();
        }
        std::cout<<"The body length is: " << snake.getSnakeBody().size() << std::endl;

        window.draw(food.getShape());
        window.draw(snake.getSnakeHead());
        window.display();
    }
}
