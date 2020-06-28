#include "snake.h"
#include <SFML/System/Vector2.hpp>

//Snake implementation here

sf::RectangleShape Snake::getSnakeHead(){
    return snakeHead;
}
Snake::Snake(){
        snakeHead = sf::RectangleShape(sf::Vector2f(10,10));
        position = sf::Vector2f(25,25);
        snakeHead.setPosition(position);
} 

void Snake::changeDirection(sf::Vector2f dir){
    direction = dir;
}

void Snake::setHeadPosition(char axis,float pos){
    switch(std::tolower(axis)){
        case 'x':
            snakeHead.setPosition(pos,snakeHead.getPosition().y);
            break;
        case 'y':
            snakeHead.setPosition(snakeHead.getPosition().x,pos);
            break;
        default:
            break;
    }
}


void Snake::update(){
   position += (direction * speed);
   //position.x += 0.2f;
   snakeHead.setPosition(position);
}


