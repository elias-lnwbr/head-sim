#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "controller/Game.h"
#include "view/InfoSheet.h"
#include "view/Utils.h"

void
InfoSheet::render()
{
    centerNextWindow(500, 320);
    if (ImGui::Begin("Fiche d'info", nullptr, ImGuiWindowFlags_NoMove)) {
        ImGui::LabelText("Nom","%s",student->getSurname().c_str());
        ImGui::LabelText("Prénom","%s",student->getFirstName().c_str());
        ImGui::LabelText("Compétence","%1.f/10",student->getSkill());
        ImGui::LabelText("Motivation", "%1.f/10", student->getMotivation());
        ImGui::LabelText("Humeur", "%.1f/10",student->getMood());
        double moyG = student->moyenneGenerale();
        if( moyG == -1.f)
            ImGui::LabelText("Moyenne générale","Aucune note");
        else
            ImGui::LabelText("Moyenne générale","%1.f",moyG);
        
        if (ImGui::Button("Revenir"))
            Game::removeComponent(this);
    }
    ImGui::End();
}
