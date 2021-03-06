#include "snake.h"
#include <SFML/Graphics/RectangleShape.hpp>
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

void Snake::increaseSpeed(){
    speed += 2;
}

void Snake::setHeadPosition(char axis,float pos){
    switch(std::tolower(axis)){
        case 'x':
            position.x = pos;
            snakeHead.setPosition(position);
            break;
        case 'y':
            position.y = pos;
            snakeHead.setPosition(position);
            break;
        default:
            break;
    }
}

void Snake::grow(){
    bodyCell cell = bodyCell(sf::RectangleShape(sf::Vector2f(10,10)));
    
   // cell.setPosition(previousPosition + (sf::operator*(snakeSize,direction)));
    cell.setPosition(previousPosition);
    snakeBody.push_back(cell); 
}

sf::Vector2f Snake::getPreviousPosition(){
    return previousPosition;
}

void Snake::update(){
    previousPosition = position;
   position += (direction * speed);
   //position.x += 0.2f;
   snakeHead.setPosition(position);
   if(snakeBody.size() > 0){
       snakeBody[0].setPosition(previousPosition); 
       for(std::size_t i = 1; i < snakeBody.size(); i++){
           snakeBody[i].setPosition(snakeBody[i-1].getPreviousPosition()); 
        }
   }
}

std::vector<bodyCell> Snake::getSnakeBody(){

    return snakeBody;
 }
sf::Vector2f Snake::getDirection(){
    return direction;
}
