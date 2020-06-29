#include "food.h"
#include <SFML/System/Vector2.hpp>

Food::Food(sf::Vector2f pos){
    foodShape = sf::RectangleShape(sf::Vector2f(10,10));
    foodShape.setFillColor(sf::Color::Red);
    foodShape.setPosition(pos);
}

void Food::setPosition(sf::Vector2f pos){
    foodShape.setPosition(pos);
}

sf::RectangleShape Food::getShape(){
    return foodShape;
}
