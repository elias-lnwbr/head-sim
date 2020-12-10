#include <algorithm>
#include <assert.h>
#include <fstream>
#include <random>
#include <sstream>
#include <stdlib.h>

#include "controller/StudentFactory.h"
#include "model/Student.h"

std::vector<Student *> StudentFactory::studentFactory;
std::string StudentFactory::filename(RESOURCES_FOLDER
                                     "actors/DataStudents.csv");

std::vector<std::string>
StudentFactory::getNextLineAndSplitIntoTokens(std::istream &stream)
{
    std::vector<std::string> result;
    std::string line;
    std::getline(stream, line);

    std::stringstream lineStream(line);
    std::string cell;

    while (std::getline(lineStream, cell, ',')) {
        result.push_back(cell);
    }
    // This checks for a trailing comma with no data after it.
    if (!lineStream && cell.empty()) {
        // If there was a trailing comma then add an empty element.
        result.push_back("");
    }
    return result;
}

void
StudentFactory::loadStudentFactory()
{
    // ouvre le fichier
    std::ifstream ifs(filename, std::ifstream::in);

    std::vector<std::string> studentline;
    while (ifs.good()) {
        studentline = getNextLineAndSplitIntoTokens(ifs);
        if (studentline.size() == 7)
            studentFactory.push_back(new Student(
              studentline[1], studentline[2], atof(studentline[3].c_str()),
              atof(studentline[4].c_str()), atof(studentline[5].c_str()), studentline[6].c_str()));
    }
    ifs.close();

    auto rd = std::random_device{ };
    auto rng = std::default_random_engine{ rd() };
    std::shuffle(std::begin(studentFactory), std::end(studentFactory), rng);
}

Student *
StudentFactory::getRandomStudent()
{
    assert(!studentFactory.empty());
    Student *rndstudent = studentFactory.back(); // la liste est mélangé point
    studentFactory.pop_back();
    return rndstudent;
}

StudentFactory::~StudentFactory()
{
    while (!studentFactory.empty()) {
        delete studentFactory.back();
        studentFactory.pop_back();
    }
}