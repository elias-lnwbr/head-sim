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
InfoSheet::render() const
{
    centerNextWindow(500, 320);
    if (ImGui::Begin("Fiche d'info", nullptr, ImGuiWindowFlags_NoMove)) {
        ImGui::LabelText("Satisfaction", "I can't get no");
        ImGui::LabelText("Humeur", "jsp");
        ImGui::LabelText("Moyenne générale", "20/20");
    }
    ImGui::End();
}
