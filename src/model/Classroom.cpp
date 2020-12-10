#include <cstring>
#include <iostream>

#include <SFML/OpenGL.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "controller/StudentFactory.h"
#include "model/Classroom.h"
#include "model/Student.h"
#include "model/Teacher.h"

#define NB_STUDENTS 5

ImGuiID Classroom::lastID = 0;

Classroom::Classroom(int n, Teacher *teacher)
  : Texturable("resources/images/salles/salle" + std::to_string(n) + ".png")
  , teacher(teacher)
{
    for (int i = 1; i <= NB_STUDENTS; ++i)
        addStudent(StudentFactory::getRandomStudent());
}

ImTextureID
convertGLTextureHandleToImTextureID(GLuint glTextureHandle)
{
    ImTextureID textureID = (ImTextureID)NULL;
    std::memcpy(&textureID, &glTextureHandle, sizeof(GLuint));
    return textureID;
}

void
Classroom::render() const
{
    ImVec2 size(ImGui::GetIO().DisplaySize.x / 2.25,
                ImGui::GetIO().DisplaySize.y / 2.25);
    if (ImGui::BeginChild(Game::getComponentID(), size, true,
                          ImGuiWindowFlags_NoBackground)) {
        ImGui::GetBackgroundDrawList()->AddImage(
          convertGLTextureHandleToImTextureID(texture.getNativeHandle()),
          ImGui::GetWindowPos(),
          ImVec2(ImGui::GetWindowPos().x + ImGui::GetContentRegionAvail().x,
                 ImGui::GetWindowPos().y + ImGui::GetContentRegionAvail().y));
        ImGui::SameLine();
        ImGui::Dummy(ImVec2(0., 120.));
        teacher->render();
        ImGui::SameLine();
        ImGui::Dummy(ImVec2(100., 20.));
        for (const Student *student : students) {
            ImGui::SameLine();
            student->render();
        }
    }
    ImGui::EndChild();
}

Classroom::~Classroom()
{
    while (!students.empty()) {
        delete students.back();
        students.pop_back();
    }
    delete teacher;
}
