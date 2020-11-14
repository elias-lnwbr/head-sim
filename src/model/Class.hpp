#include <vector>

#include "Student.hpp"
#include "Teacher.hpp"

class Class {
private:
	std::vector<Student *> students;
	Teacher &teacher;
};
