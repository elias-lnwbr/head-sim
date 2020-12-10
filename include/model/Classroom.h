#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <vector>

#include "controller/Game.h"
#include "view/Texturable.h"

class Student;
class Teacher;

class Classroom : public Texturable
{
  private:
    static const int MAX_SIZE = 50;  /**< taille maximum de la classe */
    std::vector<Student *> students; /**< élèves de la classe */
    Teacher *teacher;                /**< enseignant de la classe */

  public:
    /**
     * @brief Construct a new Classroom object
     *
     * @param teacher Professeur de la classe
     */
    Classroom(int n, Teacher *teacher) : Texturable(RESOURCES_FOLDER "images/salles/salle" + std::to_string(n) + ".png"), teacher(teacher) {
      std::cout << "créé une classroom" << std::endl;
    }
    ~Classroom();

    /**
     * @brief Get le professeur de la classe
     *
     * @return Teacher*
     */
    Teacher *getTeacher() { return teacher; }

    /**
     * @brief Get la liste des élèves
     *
     * @return std::vector<Student *> Liste des élèves
     */
    std::vector<Student *> getStudents() { return students; }

    /**
     * @brief Ajoute un élève à la classe
     *
     * @param student Elève
     */
    void addStudent(Student *student) { students.push_back(student); }

    /**
     * @brief Retourne le nombre d'élève dans la classe
     *
     * @return int nombre d'élève
     */
    int size() { return students.size(); }

    void render() const;

    const std::string &getTexturePath() const override final {
        return texturePath;
    }
};

#endif
