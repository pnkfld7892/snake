#include "bodyCell.h"
#include <SFML/System/Vector2.hpp>

sf::Vector2f bodyCell::getPos(){
    return position;
}

sf::Vector2f bodyCell::getPreviousMove(){
    return previousMove;
}
