#ifndef CLASS_H
#define CLASS_H

class Student;
class Teacher;

class Class {
private:
    std::vector<Student *> students;
    Teacher &teacher;
};

#endif
