#include <string>

#include <SFML/Graphics.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "controller/Game.h"
#include "model/Actor.h"

Actor::Actor(const std::string &firstname, const std::string &surname,
             const std::string &texturePath)
  : Texturable(texturePath)
  , firstname(firstname)
  , surname(surname)
{
}

void
Actor::render() const
{
    const char *str_id = std::to_string(Game::getComponentID()).c_str();

    if (ImGui::ImageButton(
          texture, ImVec2(texture.getSize().x / 2, texture.getSize().y / 2)))
        ImGui::OpenPopup(str_id);
    if (ImGui::BeginPopup(str_id)) {
        if (ImGui::MenuItem("Afficher fiche information")) {
        }
        if (ImGui::MenuItem("Interroger")) {
        }
        if (ImGui::MenuItem("Lancer une craie")) {
        }
        if (ImGui::MenuItem("Envoyer au coin")) {
        }
        ImGui::EndPopup();
    }
}
