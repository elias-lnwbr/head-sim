#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "controller/Game.h"
#include "controller/StudentFactory.h"
#include "view/MainView.h"
#include "view/Utils.h"

#define NB_STUDENT 10
MainView::MainView()
  : school(new School("L'école infernale"))
{
    Classroom *g12 = new Classroom(1, new Teacher("Julien", "H.", 70, 40));
    g12->addStudent(new Student("Golden", "de Noel", 80, 70, 70));
    school->addClass(g12);

    // ajout élèves
    StudentFactory::loadStudentFactory();
    for (int i(0); i < NB_STUDENT; i++)
        g12->addStudent(StudentFactory::getRandomStudent());
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
