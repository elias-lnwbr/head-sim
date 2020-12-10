#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "model/Classroom.h"
#include "model/School.h"
#include "model/Teacher.h"
#include "view/Utils.h"

School::School(const std::string &name) : name(name)
{
    std::cout << "en train de créer une school" << std::endl;
    Teacher *teacher = new Teacher("H.", "Julien", 70, 40);
    std::cout << "créé H" << std::endl;
    for (int i = 1; i <= 4; ++i)
        classrooms.push_back(new Classroom(i, teacher));
    std::cout << "créé une school" << std::endl;
}

School::~School()
{
    while (!classrooms.empty()) {
        delete classrooms.back();
        classrooms.pop_back();
    }
}

void
School::render() const
{
    maximizeNextWindow();
    if (ImGui::Begin(name.c_str(), nullptr,
                     ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove)) {
        ImGui::Columns(2, NULL);
        ImGui::Separator();
        for (int i = 0; i < 4; ++i) {
            if (i > 0 && i % 2 == 0)
                ImGui::Separator();
            classrooms[i % classrooms.size()]->render();
            ImGui::NextColumn();
        }
        ImGui::Columns(1);
        ImGui::Separator();
    }
    ImGui::End();
}
