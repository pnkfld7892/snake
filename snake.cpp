#include "snake.h"
#include <SFML/System/Vector2.hpp>

//Snake implementation here

sf::RectangleShape Snake::getSnakeHead(){
    return snakeHead;
}

void Snake::changeDirection(sf::Vector2f dir){
    direction = dir;
}


