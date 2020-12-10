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

void
Classroom::render() const
{
    if (ImGui::BeginChild(++lastID,
                          ImVec2(ImGui::GetIO().DisplaySize.x / 2.1,
                                 ImGui::GetIO().DisplaySize.y / 2.2))) {
        ImGui::Image(texture);
        ImGui::SameLine();
        for (const Student *student : students)
            student->render();
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
