#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector2.hpp>
class bodyCell{
    public:
        bodyCell(sf::RectangleShape shape){
            cellShape = shape;
        }
    private:
    sf::RectangleShape cellShape;
    sf::Vector2f position;
    sf::Vector2f currentMove;
    sf::Vector2f previousMove;
    public:
    sf::RectangleShape getShape();
    sf::Vector2f getPreviousMove();
    void setNextMove(sf::Vector2f nextMove);
    sf::Vector2f getPos(); 
};
