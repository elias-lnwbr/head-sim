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
    void newGame(const std::string &playerName);
};

#endif /* GAME_H */
