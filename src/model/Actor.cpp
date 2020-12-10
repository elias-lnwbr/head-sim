#include <SFML/Graphics.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

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
    ImGui::ImageButton(
      texture, ImVec2(texture.getSize().x / 2, texture.getSize().y / 2));
}
