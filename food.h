#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
class Food{
    public:
        Food(sf::Vector2f position);
        sf::RectangleShape getShape();
    private:
        sf::RectangleShape foodShape;
};
