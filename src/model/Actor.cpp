#include <iostream>

#include "model/Actor.h"

Actor::Actor(const std::string &name,
             const std::string &surname,
             const std::string &texturePath)
  : Texturable(texturePath)
  , name(name)
  , surname(surname)
{}
