#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "controller/Game.h"

#define RESOURCES_FOLDER "resources/"

/**
 * Point d'entrée principal.
 */
int
main()
{
    /* Démarre le chronomètre. */
    sf::Clock clock;

    /* Chargement des ressources, initialisation des états OpenGL... */
    sf::Font font;
    if (!font.loadFromFile(RESOURCES_FOLDER "fonts/Roboto-Light.ttf"))
        return EXIT_FAILURE;

    Game::newGame(clock);

    return EXIT_SUCCESS;
}
