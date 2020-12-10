#ifndef GAME_H
#define GAME_H

#include <vector>

#include <SFML/System.hpp>

#include "view/Component.h"
#include "view/GameWindow.h"

#define RESOURCES_FOLDER "resources/"

/** @brief Une classe "statique" ("singleton") modélisant le jeu. */
class Game
{
  private:
    static GameWindow *mainWindow;
    static std::vector<Component *> components;

  public:
    Game() = delete;

    /** @brief Démarre le jeu. */
    static void start();

    /**
     * @brief La boucle de jeu principale.
     *
     * @param clock le chronomètre du processus principal
     */
    static void loop(sf::Clock &clock);

    /** @brief Débute une nouvelle partie. */
    static void newGame();

    /** @brief Termine le jeu. */
    static void end();

    /**
     * @brief Renvoie une référence vers la fenêtre principale.
     *
     * @return une référence vers la fenêtre principale
     */
    static GameWindow &getMainWindow();

    /** @brief Donne le signal d'arrêter le jeu. */
    static void stop();

    /**
     * @brief Ajoute un composant graphique au jeu.
     *
     * @param component un composant graphique
     */
    static void addComponent(Component *component);

    /**
     * @brief Supprime un composant graphique du jeu.
     *
     * @param component un composant graphique
     */
    static void removeComponent(Component *component);

    /** @brief Supprime tous les composants graphiques du jeu. */
    static void clearComponents();
};

#endif /* GAME_H */
