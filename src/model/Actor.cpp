#include <string>

#include "Actor.h"

void
Actor::setName(std::string name)
{
    this->name = name;
}


std::string
Actor::getName()
{
    return this->name;
}
