#pragma once

#include<SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
class Snake{
private:
    std::vector<sf::RectangleShape> snakeBody;
    sf::RectangleShape snakeHead;
    sf::Vector2f position;
    sf::Vector2f direction;
public:
    void changeDirection(sf::Vector2f direction);
    void update();
    sf::RectangleShape getSnakeHead();
    std::vector<sf::RectangleShape> getSnakeBody();
};
