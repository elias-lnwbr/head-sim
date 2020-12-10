#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "controller/StudentFactory.h"
#include "model/Classroom.h"
#include "model/School.h"
#include "model/Teacher.h"
#include "view/Utils.h"

#define NB_CLASSES 4

School::School(const std::string &name)
  : name(name)
{
    for (int i = 1; i <= NB_CLASSES; ++i) {
        Student *dummy = StudentFactory::getRandomStudent();
        classrooms.push_back(new Classroom(
          i, new Teacher(dummy->getFirstName(), dummy->getSurname(),
                         dummy->getMotivation(), dummy->getSkill())));
    }
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
    if (ImGui::Begin(name.c_str(), nullptr, ImGuiWindowFlags_NoResize |
                                              ImGuiWindowFlags_NoMove |
                                              ImGuiWindowFlags_NoBackground)) {
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
