#pragma once

#include <string>

class Actor {
private:
	std::string name;
public:
	void setName(std::string);
	std::string getName();
};
