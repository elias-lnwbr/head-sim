#include "assert.h"

#include <iostream>

#include "controller/Game.h"
#include "view/GameWindow.h"

GameWindow::GameWindow()
  : sf::RenderWindow(sf::VideoMode::getDesktopMode(),
                     "Headmaster Simulator",
                     sf::Style::Default)
  , background(0.f, 0.f, 0.f)
{
    sf::Image icon;
    assert(icon.loadFromFile(RESOURCES_FOLDER "images/hms-logo-128.jpg"));
    setIcon(128, 128, icon.getPixelsPtr());

    setVerticalSyncEnabled(true);
    resetGLStates();

    ImGui::SFML::Init(*this,
                      static_cast<sf::Vector2f>(getSize()),
                      true,
                      RESOURCES_FOLDER "fonts/Roboto-Light.ttf",
                      32.f);

    /* Activation de la fenêtre. */
    setActive(true);
}

void
GameWindow::handleEvents()
{
    sf::Event event;

    while (pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed) {
            /* Stoppe le programme. */
            close();
        } else if (event.type == sf::Event::Resized) {
            /* Ajuste le viewport lorsque la fenêtre est redimensionnée. */
            glViewport(0, 0, event.size.width, event.size.height);
        }
    }
}

void
GameWindow::draw()
{
    clear(background);
    ImGui::SFML::Render();
}

GameWindow::~GameWindow()
{
    setActive(false);
    ImGui::SFML::Shutdown();
}
