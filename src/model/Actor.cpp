#include "Actor.hpp"

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
