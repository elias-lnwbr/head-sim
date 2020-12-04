#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>

#include "model/Actor.h"
#include "view/GameWindow.h"

#define RESOURCES_FOLDER "resources/"

/**
 * Point d'entrée principal.
 */
int
main()
{
    /* Crée la fenêtre. */
    sf::RenderWindow window(sf::VideoMode(800, 600),
                            "Headmaster Simulator",
                            sf::Style::Default,
                            sf::ContextSettings(24, 0, 0, 4, 6));
    window.setVerticalSyncEnabled(false);

    /* Activation de la fenêtre. */
    window.setActive(true);

    /* Chargement des ressources, initialisation des états OpenGL... */
    sf::Font font;
    if (!font.loadFromFile(RESOURCES_FOLDER "Roboto-Light.ttf"))
        return EXIT_FAILURE;
    sf::Text text;
    text.setFont(font);
    text.setString("Barre oblique");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.move(50.0f, 250.0f);

    /* Démarre le chronomètre. */
    sf::Clock clock;

    sf::RectangleShape line(sf::Vector2f(150, 5));
    line.rotate(-45);
    line.move(50.0f, 200.0f);

    /* La boucle de jeu principale. */
    bool running = true;
    while (running) {
        /* Gestion des évènements. */
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                /* Stoppe le programme. */
                running = false;
            } else if (event.type == sf::Event::Resized) {
                /* Ajuste le viewport lorsque la fenêtre est redimensionnée. */
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        /* Effacement des tampons de couleur et de profondeur. */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /* Dessin. */
        window.draw(line);
        window.draw(text);

        /*
         * Termine la trame courante (en interne, échange les deux tampons de
         * rendu).
         */
        window.display();
    }

    /* Libération des ressources. */
    window.setActive(false);

    return EXIT_SUCCESS;
}
