#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

#include "model/Actor.h"
#include "view/GameWindow.h"

#define RESOURCES_FOLDER "resources/"

/**
 * @brief Point d'entrée principal.
 */
int
main()
{
    /* Crée la fenêtre. */
    sf::RenderWindow window(sf::VideoMode(800, 600),
                            "Headmaster Simulator",
                            sf::Style::Default,
                            sf::ContextSettings(24, 0, 0, 4, 6));
    window.setVerticalSyncEnabled(true);

    ImGui::SFML::Init(window);
    sf::Color bgColor(0.f, 0.5f, 0.5f, 0.0f);
    window.resetGLStates();

    /* Activation de la fenêtre. */
    window.setActive(true);

    /* Chargement des ressources, initialisation des états OpenGL... */
    sf::Font font;
    if (!font.loadFromFile(RESOURCES_FOLDER "fonts/Roboto-Light.ttf"))
        return EXIT_FAILURE;

    /* Démarre le chronomètre. */
    sf::Clock clock;

    /* La boucle de jeu principale. */
    bool running = true;
    while (running) {
        /* Gestion des évènements. */
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed) {
                /* Stoppe le programme. */
                running = false;
            } else if (event.type == sf::Event::Resized) {
                /* Ajuste le viewport lorsque la fenêtre est redimensionnée. */
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        ImGui::SFML::Update(window, clock.restart());
        if (ImGui::Begin("test", nullptr, ImGuiWindowFlags_NoTitleBar |
            ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove)) {
            if (ImGui::Button("coucou"))
                std::cout << "test" << std::endl;
            if (ImGui::Button("coucou2"))
                std::cout << "test" << std::endl;
            ImGui::Dummy(ImVec2(ImGui::GetContentRegionAvail().x - 200, 0));
            ImGui::SameLine();
            if (ImGui::Button("coucou3"))
                std::cout << "test" << std::endl;
        }
        ImGui::End();

        /* Dessin. */
        window.clear(bgColor);
        ImGui::SFML::Render();

        /*
         * Termine la trame courante (en interne, échange les deux tampons de
         * rendu).
         */
        window.display();
    }

    /* Libération des ressources. */
    window.setActive(false);
    ImGui::SFML::Shutdown();

    return EXIT_SUCCESS;
}
