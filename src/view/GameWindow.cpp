#include "view/GameWindow.h"

#define RESOURCES_FOLDER "resources/"

GameWindow::GameWindow(unsigned int width, unsigned int height) :
sf::RenderWindow(sf::VideoMode(width, height), "Headmaster Simulator",
                 sf::Style::Default, sf::ContextSettings(24, 0, 0, 4, 6)),
background(0.f, 0.f, 0.f)
{
    setVerticalSyncEnabled(true);
    resetGLStates();

    ImGui::SFML::Init(*this, static_cast<sf::Vector2f>(getSize()), true,
                      RESOURCES_FOLDER "fonts/Roboto-Light.ttf", 32.f);

    /* Activation de la fenêtre. */
    setActive(true);
}

void
GameWindow::handleEvents(bool &running)
{
    sf::Event event;

    while (pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed) {
            /* Stoppe le programme. */
            running = false;
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
