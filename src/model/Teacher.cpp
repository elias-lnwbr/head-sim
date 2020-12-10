#include <iostream>

#include "model/Actor.h"
#include "model/Teacher.h"

Teacher::Teacher(const std::string &name, const std::string &surname,
                 double pedagogie, double meritocratic)
  : Actor(name, surname, "resources/images/profs/prof1.png")
  , pedagogue(pedagogie)
  , meritocratic(meritocratic)
{
    std::cout << "créé un teacher" << std::endl;
}
