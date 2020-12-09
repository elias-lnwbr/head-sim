#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

#include "controller/Game.h"
#include "view/MainMenu.h"

void
MainMenu::render()
{
    if (ImGui::Begin("Menu principal", nullptr, ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove)) {
        if (ImGui::Button("Nouvelle partie"))
            std::cout << "Nouvelle partie" << std::endl;
        if (ImGui::Button("Quitter"))
            Game::end();
    }
    ImGui::End();
}
