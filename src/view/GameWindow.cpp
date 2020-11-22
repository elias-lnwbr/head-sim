#include <string>

#include "GameWindow.h"

GameWindow::GameWindow(const std::string &title)
{
    create(sf::VideoMode(800, 600), title);
}
