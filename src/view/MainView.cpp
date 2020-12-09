#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

#include "controller/Game.h"
#include "view/MainView.h"
#include "view/Utils.h"

MainView::MainView()
{
    assert(classroom.loadFromFile("resources/images/salles/salle1.png"));
}

void
MainView::render() const
{
    centerNextWindow(700, 500);
    if (ImGui::Begin("École", nullptr, ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove)) {
        if (ImGui::Button("Démissionner"))
            std::cout << "aled" << std::endl;
        ImGui::Image(classroom);
    }
    ImGui::End();
}
