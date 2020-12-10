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
{
    Classroom *g12 = new Classroom(1, new Teacher("H.", "Julien", 70, 40));
    g12->addStudent(new Student("de Noel", "Golden", 80, 70, 70));
    school->addClass(g12);
}

MainView::~MainView()
{
    delete school;
}

void
MainView::render() const
{
    school->render();
}
