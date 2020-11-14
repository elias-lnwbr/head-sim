#include <vector>

#include "Student.h"
#include "Teacher.h"

class Class {
private:
	std::vector<Student *> students;
	Teacher &teacher;
};
