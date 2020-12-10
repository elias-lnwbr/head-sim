#include <stdlib.h>

#include <SFML/System.hpp>

#include "controller/Game.h"

/** @brief Point d'entrée principal. */
int
main()
{
    /* Démarre le chronomètre. */
    sf::Clock clock;

    Game::start();
    Game::loop(clock);
    Game::end();

    exit(EXIT_SUCCESS);
    /* NOTREACHED */
}
