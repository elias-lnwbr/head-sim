#include <iostream>

#include "model/Actor.h"

Actor::Actor(const std::string &firstname, const std::string &surname,
             const std::string &texturePath)
  : Texturable(texturePath)
  , firstname(firstname)
  , surname(surname)
{
}
