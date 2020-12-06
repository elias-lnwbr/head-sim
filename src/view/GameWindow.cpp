#include <string>

#include <SFML/Window.hpp>

#include "GameWindow.h"

GameWindow::GameWindow() :
sf::RenderWindow(sf::VideoMode(800, 600), "Headmaster Simulator",
                 sf::Style::Default, sf::ContextSettings(24, 0, 0, 4, 6))
{
    setVerticalSyncEnabled(true);
}
