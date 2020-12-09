#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "controller/Game.h"
#include "view/MainView.h"
#include "view/Utils.h"

MainView::MainView()
{
    sf::Texture *classroom = new sf::Texture;
    char path[35];

    sprintf(path, RESOURCES_FOLDER "images/salles/salle1.png");
    while (classroom->loadFromFile(path)) {
        classrooms.push_back(classroom);
        classroom = new sf::Texture;
        ++path[29]; // grosse magie noire mythique ici.
    }
}

MainView::~MainView()
{
    while (!classrooms.empty()) {
        delete classrooms.back();
        classrooms.pop_back();
    }
}

void
MainView::render() const
{
    maximizeNextWindow();
    if (ImGui::Begin("École", nullptr,
                     ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove)) {
        ImGui::Columns(2, NULL);
        ImGui::Separator();
        ImVec2 size(ImGui::GetIO().DisplaySize.x / 2.1,
                    ImGui::GetIO().DisplaySize.y / 2.2);
        for (int i = 0; i < 4; ++i) {
            if (i > 0 && i % 2 == 0)
                ImGui::Separator();
            ImGui::ImageButton(*classrooms[i % classrooms.size()], size);
            ImGui::NextColumn();
        }
        ImGui::Columns(1);
        ImGui::Separator();
    }
    ImGui::End();
}
