#ifndef GAME_H
#define GAME_H

#include "view/GameWindow.h"

/**
 * @brief Le contrôleur du jeu.
 */
class Game {
private:
    static GameWindow *mainWindow;

public:
    /**
     * @brief Démarre le jeu.
     * 
     * @param playerName le nom du joueur
     */
    static void start(sf::Clock &clock);

    static void newGame();

    /**
     * @brief Termine le jeu.
     */
    static void end();

    /**
     * @brief Get the Main Window object
     * 
     * @return GameWindow& the Main Window object
     */
    static GameWindow &getMainWindow() { return *mainWindow; }
};

#endif /* GAME_H */
