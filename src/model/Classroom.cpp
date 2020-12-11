#include <cstring>
#include <iostream>

#include <SFML/OpenGL.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "controller/StudentFactory.h"
#include "model/Classroom.h"
#include "model/Student.h"
#include "model/Subject.h"
#include "model/Teacher.h"

#define NB_STUDENTS 5

static ImTextureID
convertGLTextureHandleToImTextureID(GLuint glTextureHandle)
{
    ImTextureID textureID = (ImTextureID)NULL;
    std::memcpy(&textureID, &glTextureHandle, sizeof(GLuint));
    return textureID;
}

ImGuiID Classroom::lastID = 0;

Classroom::Classroom(int n, Teacher *teacher)
  : Texturable("resources/images/salles/salle" + std::to_string(n) + ".png")
  , teacher(teacher)
{
    for (int i = 1; i <= NB_STUDENTS; ++i)
        addStudent(StudentFactory::getRandomStudent());
}

void
Classroom::render()
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
        if (ImGui::Button("Examen")) {
            examen();
        }
        ImGui::SameLine();
        ImGui::Dummy(ImVec2(0., 120.));
        teacher->render();
        ImGui::SameLine();
        ImGui::Dummy(ImVec2(100., 20.));
        for (Student *student : students) {
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

void
Classroom::examen() const
{
    double grade;
    for (Student *s : students) {
        grade = (teacher->getMeritocratic() * s->getSkill()) / 10 +
                (teacher->getPedagogue() * s->getMotivation()) /
                  10; // note sur 20 en fonction du skill et de la motivation de
                      // l'élève et du type d'enseignement du prof
        grade +=
          s->getMood() *
          0.2; // entre 0 et 2 points bonus en fonction du mood de l'élève
        s->addGrades(new Subject("Maths", 2.), grade);
    }
}
