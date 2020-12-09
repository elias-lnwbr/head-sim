#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

#include "controller/Game.h"
#include "view/MainMenu.h"
#include "view/MainView.h"

void
MainMenu::render() const
{
    if (ImGui::Begin("Menu principal", nullptr, ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove)) {
        if (ImGui::Button("Nouvelle partie"))
            Game::newGame();
        if (ImGui::Button("Quitter"))
            Game::end();
    }
    ImGui::End();
}
