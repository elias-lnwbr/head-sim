#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "model/Actor.h"
#include "model/Student.h"

Student::Student(const std::string &firstname, const std::string &surname,
                 double mood, double motivation, double skill)
  : Actor(firstname, surname, "resources/images/eleves/eleve_garcon1.png")
  , mood(mood)
  , motivation(motivation)
  , skill(skill)
{
}

void
Student::addGrades(Subject *subject, double grade)
{
    if (grades.count(subject) > 0)
        grades.at(subject).push_back(grade);
    else
        grades.emplace(subject, std::vector<double>());
}
