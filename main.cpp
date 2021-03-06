#include <SFML/Graphics.hpp>
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

//
bool checkSnakeCollision(Snake* snake){
    for(bodyCell cell : snake->getSnakeBody()){
        if(snake->getSnakeHead().getGlobalBounds().intersects(cell.getShape().getGlobalBounds())){
            std::cout<<"Game over" << std::endl;
            return true;
        }
    }
        return false;
}

int main(){
    std::cout <<"welcome to snake" << std::endl;
    sf::RenderWindow window(sf::VideoMode(640,480),"Snake!");

    bool gameOver = false;
    window.setFramerateLimit(60);
    
    Snake snake; 
    Food food(sf::Vector2f(150,220));
    snake.changeDirection(sf::Vector2f(1,0));
    while (window.isOpen() && !gameOver)
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
                                  if(snake.getDirection() != direction["Down"])
                                        snake.changeDirection(direction["Up"]);
                                    break;
                              case sf::Keyboard::Down:
                                    if(snake.getDirection() != direction["Up"])
                                        snake.changeDirection(direction["Down"]);
                                    break;
                              case sf::Keyboard::Left:
                                    if(snake.getDirection() != direction["Right"]){
                                        snake.changeDirection(direction["Left"]);
                                    }
                                    break;
                              case sf::Keyboard::Right:
                                    if(snake.getDirection() != direction["Left"])
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
        
       gameOver = checkSnakeCollision(&snake);

        if(snake.getSnakeHead().getGlobalBounds().intersects(food.getShape().getGlobalBounds())){
            food.setPosition(sf::Vector2f(std::rand() % window.getSize().x + 1,std::rand() % window.getSize().y));
//            snake.increaseSpeed();
            snake.grow();
        }

        window.draw(food.getShape());
        window.draw(snake.getSnakeHead());
        for (bodyCell cell : snake.getSnakeBody()){
            window.draw(cell.getShape());
         }

        window.display();
    }
}
