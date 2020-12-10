#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "model/Classroom.h"
#include "model/Student.h"
#include "model/Teacher.h"

void
Classroom::render() const
{
    ImGui::ImageButton(texture, ImVec2(ImGui::GetIO().DisplaySize.x / 2.1,
                    ImGui::GetIO().DisplaySize.y / 2.2));
}

Classroom::~Classroom()
{
    while (!students.empty()) {
        delete students.back();
        students.pop_back();
    }
    delete teacher;
}
