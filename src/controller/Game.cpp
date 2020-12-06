#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

#include "controller/Game.h"
#include "view/GameWindow.h"

void
Game::newGame(sf::Clock &clock)
{
    /* Crée la fenêtre. */
    GameWindow window(800, 600);

    /* La boucle de jeu principale. */
    bool running = true;
    while (running) {
        window.handleEvents(running);

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

        window.draw();
        window.display();
    }
}
