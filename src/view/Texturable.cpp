#include "assert.h"

#include <iostream>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "view/Texturable.h"

Texturable::Texturable(const std::string &filename) : texturePath(filename), texture(sf::Texture())
{
    std::cout << "About to load texture..." << std::endl;
    std::cout << "texturePath = \"" << texturePath << "\"" << std::endl;
    assert(texture.loadFromFile(texturePath));
}

void
Texturable::render() const
{
    ImGui::ImageButton(texture);
}

// a redefinir !!!!
const std::string &
Texturable::getTexturePath() const
{
    return "";
}
