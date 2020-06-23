#pragma once

#include<SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

private:
    std::vector<sf::RectangleShape> snakeShape;
    sf::Vector2f position;
    sf::Vector2f direction;
public:
    void changeDirection(sf::Vector2f direction)
    void update()

