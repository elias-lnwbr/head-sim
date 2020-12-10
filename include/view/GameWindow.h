#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Graphics.hpp>

/** @brief La fenêtre principale du jeu. */
class GameWindow : public sf::RenderWindow {
  private:
    sf::Color background;

  public:
    /** @brief Construit une fenêtre de jeu. */
    GameWindow();

    /** @brief Gestion des évènements. */
    void handleEvents();

    /** @brief Dessin et rendu. */
    void draw();

    /** @brief Libération des ressources. */
    ~GameWindow();
};

#endif /* GAMEWINDOW_H */
