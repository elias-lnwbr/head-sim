#include "assert.h"

#include <string>

#include <SFML/Graphics.hpp>

#include "imgui/imgui-SFML.h"

#include "view/Texturable.h"

Texturable::Texturable(const std::string &filename)
  : texturePath(filename)
  , texture(sf::Texture())
{
    assert(texture.loadFromFile(texturePath));
}

void
Texturable::render() const
{
    ImGui::ImageButton(texture);
}
