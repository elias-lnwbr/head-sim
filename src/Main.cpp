#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "controller/Game.h"

/**
 * Point d'entrée principal.
 */
int
main()
{
    /* Démarre le chronomètre. */
    sf::Clock clock;

    Game::start();
    Game::loop(clock);
    Game::end();

    std::cout << "Success" << std::endl;
    return EXIT_SUCCESS;
}
