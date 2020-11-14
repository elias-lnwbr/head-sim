#include "Actor.hpp"

/**
 * @brief Set name of actor.
 * 
 * @param name new name for actor
 */
void
Actor::setName(std::string name)
{
	this->name = name;
}

/**
 * @brief Returns name of actor.
 * 
 * @return std::string name of actor
 */
std::string
Actor::getName()
{
	return this->name;
}
