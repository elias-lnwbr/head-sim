#include <iostream>

#include "model/Actor.h"

int
main(int argc, char *argv[])
{
	Actor a;

	a.setName("Bob");
	std::cout << a.getName() << std::endl;
}
