#ifndef GAME_H
#define GAME_H

class Game {
private:
    time_t startTime;
    int difficulty;
    std::string playerName;

public:
    Game() = delete;
    Game(int difficulty, std::string playerName);

    /**
     * @brief Set the Player Name object
     * 
     * @param playerName 
     */
    void setPlayerName(const std::string &playerName) { this->playerName = playerName; };

    /**
     * @brief Get the Player Name object
     * 
     * @return std::string 
     */
    std::string getPlayerName() { return playerName; };
};

#endif
