#pragma once

#include <SFML/System/Vector2.hpp>
#include <map>
#include <string>
std::map<std::string,sf::Vector2f>direction = {
    {"Up",sf::Vector2f(0,-1)},
    {"Down", sf::Vector2f(0,1)},
    {"Left", sf::Vector2f(-1,0)},
    {"Right",sf::Vector2f(1,0)}
};
