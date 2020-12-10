#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "controller/Game.h"
#include "view/MainView.h"
#include "view/Utils.h"

MainView::MainView()
  : school(new School("L'école infernale"))
{}

MainView::~MainView()
{
    delete school;
}

void
MainView::render() const
{
    school->render();
}
