#include "assert.h"

#include <algorithm>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "controller/Game.h"
#include "view/GameWindow.h"
#include "view/MainMenu.h"
#include "view/MainView.h"

GameWindow *Game::mainWindow = nullptr;
bool Game::running = true;
std::vector<Component *> Game::components = std::vector<Component *>();

void
Game::start()
{
    /* Crée la fenêtre. */
    mainWindow = new GameWindow;

    addComponent(new MainMenu);
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
Game::newGame()
{
    clearComponents();
    addComponent(new MainView);
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
    clearComponents();
}

GameWindow &
Game::getMainWindow()
{
    return *mainWindow;
}

void
Game::stop()
{
    running = false;
}

void
Game::addComponent(Component *component)
{
    assert(component);
    components.push_back(component);
}

void
Game::removeComponent(Component *component)
{
    assert(component);
    components.erase(
      std::remove(components.begin(), components.end(), component),
      components.end());
    delete component;
}

void
Game::clearComponents()
{
    for (Component *component : components)
        removeComponent(component);
}
