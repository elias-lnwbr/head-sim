#ifndef GAME_H
#define GAME_H

/**
 * @brief Le contrôleur du jeu.
 */
class Game {
public:
    /**
     * @brief Commence une nouvelle partie.
     * 
     * @param playerName le nom du joueur
     */
    static void newGame(sf::Clock &clock);
};

#endif /* GAME_H */
