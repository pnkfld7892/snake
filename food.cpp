#include "food.h"

Food::Food(sf::Vector2f pos){
    foodShape = sf::RectangleShape(sf::Vector2f(5,5));
    foodShape.setPosition(pos);
}

sf::RectangleShape Food::getShape(){
    return foodShape;
}
