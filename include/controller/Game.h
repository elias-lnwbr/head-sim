#ifndef GAME_H
#define GAME_H

#include "assert.h"

#include <algorithm>
#include <vector>

#include "view/Component.h"
#include "view/GameWindow.h"

/**
 * @brief Le contrôleur du jeu.
 */
class Game {
private:
    static GameWindow *mainWindow;
    static bool running;
    static std::vector<Component *> components;

public:
    /**
     * @brief Démarre le jeu.
     */
    static void start();

    static void newGame();

    /**
     * @brief La boucle de jeu principale.
     * 
     * @param clock 
     */
    static void loop(sf::Clock &clock);

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

    /**
     * @brief Stop
     */
    static void stop() { running = false; }

    static void addComponent(Component *component) { components.push_back(component); }

    static void removeComponent(Component *component) {
        assert(component);
        components.erase(std::remove(components.begin(), components.end(), component), components.end());
        delete component;
    }
};

#endif /* GAME_H */
