#include <cstring>
#include <iostream>

#include <SFML/OpenGL.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "model/Classroom.h"
#include "model/Student.h"
#include "model/Teacher.h"

ImGuiID Classroom::lastID = 0;

Classroom::Classroom(int n, Teacher *teacher)
  : Texturable("resources/images/salles/salle" + std::to_string(n) + ".png")
  , teacher(teacher)
{
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
    ImVec2 size(ImGui::GetIO().DisplaySize.x / 2.5,
                ImGui::GetIO().DisplaySize.y / 2.5);
    if (ImGui::BeginChild(Game::getComponentID(), size)) {
        // ImGui::SameLine();
        ImGui::GetBackgroundDrawList()->AddImage(
          convertGLTextureHandleToImTextureID(texture.getNativeHandle()),
          ImGui::GetWindowPos(),
          ImVec2(ImGui::GetWindowPos().x + ImGui::GetContentRegionAvail().x,
                 ImGui::GetWindowPos().y + ImGui::GetContentRegionAvail().y));
        // ImGui::Image(texture, size);
        for (const Student *student : students) {
            // std::cout << "rendering student" << std::endl;
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
