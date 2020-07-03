#include "bodyCell.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

sf::Vector2f bodyCell::getPos(){
    return position;
}

sf::Vector2f bodyCell::getPreviousPosition(){
    return previousPosition;
}

void bodyCell::setPosition(sf::Vector2f pos){
    previousPosition = position;
   position =  pos;
   cellShape.setPosition(position);
}

sf::RectangleShape bodyCell::getShape(){
    return cellShape;
}
