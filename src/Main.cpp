#include <stdlib.h>

#include <SFML/System.hpp>

#include "controller/Game.h"

/** @brief Point d'entrée principal. */
int
main()
{
    /* Démarre le chronomètre. */
    sf::Clock clock;

    Game::play(clock);

    exit(EXIT_SUCCESS);
    /* NOTREACHED */
}
