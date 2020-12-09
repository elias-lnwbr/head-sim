#include "assert.h"

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

#include "controller/Game.h"
#include "view/GameWindow.h"
#include "view/MainMenu.h"
#include "view/MainView.h"

GameWindow *Game::mainWindow = nullptr;

void
Game::start(sf::Clock &clock)
{
    /* Crée la fenêtre. */
    mainWindow = new GameWindow(800, 600);
    MainMenu mainMenu;

    /* La boucle de jeu principale. */
    bool running = true;
    while (running) {
        mainWindow->handleEvents(running);

        ImGui::SFML::Update(*mainWindow, clock.restart());
        mainMenu.render();

        mainWindow->draw();
        mainWindow->display();
    }
}

void
Game::newGame()
{
    MainView mainView;
    mainView.render();
}

void
Game::end()
{
    /*
     * Il faut que la fenêtre aie été créée auparavant via la méthode
     * Game::newGame.
     */
    assert(Game::mainWindow);

    delete Game::mainWindow;
}
