#include "model/Student.h"

void Student::addGrades(Subject *subject, double grade){
    if( grades.count(subject) > 0 ){ // subject already in the map
        grades.at(subject).push_back(grade);
    }else{
        std::vector<double> gr;
        grades.emplace(subject,gr);
    }
}