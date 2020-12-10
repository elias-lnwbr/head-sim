#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
  private:
    /**
     * @brief Heure de début de la partie
     *
     */
    time_t startTime;

    /**
     * @brief Difficulté de la partie
     *
     */
    int difficulty;

    /**
     * @brief Nom du joueur
     *
     */
    std::string playerName;

  public:
    /**
     * @brief Construct une nouvelle partie de jeu
     *
     * @param difficulty Difficulté de la partie
     * @param playerName Nom du joueur
     */
    Game(int difficulty, std::string playerName);
    ~Game();

    /**
     * @brief Set le nom du Joueur
     *
     * @param playerName
     */
    void setPlayerName(const std::string &playerName)
    {
        this->playerName = playerName;
    };

    /**
     * @brief Get le nom du joueur
     *
     * @return std::string
     */
    std::string getPlayerName() { return playerName; };

    /**
     * @brief Retourne le temps depuis le lancement de la partie
     *
     * @return time_t
     */
    time_t getDuration() { return time(nullptr) - startTime; };
};

#endif
