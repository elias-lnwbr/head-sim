#include <SFML/OpenGL.hpp>

#include "Time.h"

float
Utils::getDeltaTime(const sf::Clock &clock) {
    clock.restart();
    return clock.getElapsedTime().asSeconds();
}
