#include <iostream>

#include "model/Actor.h"
#include "model/Teacher.h"

Teacher::Teacher(const std::string &firstname, const std::string &surname,
                 double pedagogie, double meritocratic)
  : Actor(firstname, surname, "resources/images/profs/prof1.png")
  , pedagogue(pedagogie)
  , meritocratic(meritocratic)
{
}
