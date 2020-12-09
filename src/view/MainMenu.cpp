#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "controller/Game.h"
#include "view/MainMenu.h"
#include "view/MainView.h"
#include "view/Utils.h"

void
MainMenu::render() const
{
    centerNextWindow(320, 580);
    if (ImGui::Begin("Menu principal", nullptr, ImGuiWindowFlags_NoTitleBar |
                                                  ImGuiWindowFlags_NoResize |
                                                  ImGuiWindowFlags_NoMove)) {

        if (ImGui::Button("Nouvelle partie"))
            Game::newGame();
        if (ImGui::Button("Quitter"))
            Game::end();
    }
    ImGui::End();
}
