#pragma once
#include <SFML/Graphics.hpp>

class bodyCell{
    public:
        bodyCell(sf::RectangleShape shape){
            cellShape = shape;
        }
    private:
    sf::RectangleShape cellShape;
    sf::Vector2f position;
    sf::Vector2f previousPosition;
    public:
    sf::RectangleShape getShape();
    void setPosition(sf::Vector2f);
    sf::Vector2f getPreviousPosition();
    void setNextMove(sf::Vector2f nextMove);
    sf::Vector2f getPos(); 
};
