#pragma once

#include<SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include "bodyCell.h"
class Snake{
public:
    Snake();
private:
    std::vector<bodyCell> snakeBody;
    sf::RectangleShape snakeHead;
    sf::Vector2f position;
    const sf::Vector2f snakeSize = sf::Vector2f(10,10);
    sf::Vector2f previousPosition;
    sf::Vector2f direction;
    float speed = 10.0f;
    void move();
public:
    void changeDirection(sf::Vector2f direction);
    sf::Vector2f getPreviousPosition();
    void setHeadPosition(char axis,float pos);
    sf::Vector2f getDirection();
    void update();
    void grow();
    void increaseSpeed();
    sf::RectangleShape getSnakeHead();
    std::vector<bodyCell> getSnakeBody();
};
