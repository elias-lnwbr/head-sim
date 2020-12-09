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

GameWindow              *Game::mainWindow = nullptr;
bool                     Game::running    = true;
std::vector<Component *> Game::components = std::vector<Component *>();

void
Game::start()
{
    /* Crée la fenêtre. */
    mainWindow = new GameWindow(800, 600);

    addComponent(new MainMenu);
}

void
Game::newGame()
{
    components.clear();
    addComponent(new MainView);
}

void
Game::loop(sf::Clock &clock)
{
    while (running) {
        mainWindow->handleEvents(running);
        ImGui::SFML::Update(*mainWindow, clock.restart());
        for (const Component *component : components)
            component->render();
        mainWindow->draw();
        mainWindow->display();
    }
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
