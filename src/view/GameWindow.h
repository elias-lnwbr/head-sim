#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Window.hpp>

class GameWindow : sf::Window {
public:
    /**
     * @brief Construct a new Game Window object
     * 
     * @param title Title of the window
     */
    GameWindow(const std::string &title);
};

#endif
