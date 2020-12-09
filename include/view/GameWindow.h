#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "assert.h"

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

/**
 * @brief La fenêtre principale du jeu.
 */
class GameWindow : public sf::RenderWindow
{
  private:
    sf::Color background;

  public:
    /**
     * @brief Construit une fenêtre de jeu.
     *
     * @param width
     * @param height
     */
    GameWindow(unsigned int width, unsigned int height);

    /**
     * Gestion des évènements.
     *
     * @param running
     */
    void handleEvents(bool &running);

    /**
     * Dessin et rendu.
     */
    void draw();

    /**
     * Libération des ressources.
     */
    ~GameWindow();
};

#endif /* GAMEWINDOW_H */
