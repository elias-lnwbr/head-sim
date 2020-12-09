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

    Game::start(clock);

    return EXIT_SUCCESS;
}
