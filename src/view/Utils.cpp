#include <SFML/System.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "controller/Game.h"
#include "view/Utils.h"

void
maximizeNextWindow()
{
    sf::Vector2u mainWindowSize = getMainWindowSize();
    centerNextWindow(mainWindowSize.x, mainWindowSize.y);
}

void
centerNextWindow(float width, float height)
{
    sf::Vector2u mainWindowSize = getMainWindowSize();
    ImGui::SetNextWindowPos(
      ImVec2((mainWindowSize.x - width) / 2, (mainWindowSize.y - height) / 2));
    ImGui::SetNextWindowSize(ImVec2(width, height));
}

sf::Vector2u
getMainWindowSize()
{
    return Game::getMainWindow().getSize();
}
