#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <string>
#include <vector>

#include "imgui/imgui.h"

#include "controller/Game.h"
#include "model/Student.h"
#include "model/Teacher.h"
#include "view/Texturable.h"

class Student;

/**
 * @brief Modélise une salle de classe.
 */
class Classroom : public Texturable {
  private:
    /** @brief Taille maximum de la classe. */
    static const int MAX_SIZE = 36;

    static ImGuiID lastID;

    /** @brief Élèves de la classe. */
    std::vector<Student *> students;

    /** @brief Enseignant de la classe. */
    Teacher *teacher;

  public:
    /**
     * @brief Crée une salle de classe.
     *
     * @param n       l'identifiant de la salle de classe
     * @param teacher un pointeur vers l'enseignant de la classe
     */
    Classroom(int n, Teacher *teacher);

    /**
     * @brief Renvoie un pointeur vers l'enseignant de la classe.
     *
     * @return un pointeur vers l'enseignant de la classe
     */
    const Teacher *getTeacher() { return teacher; }

    /**
     * @brief Ajoute un élève à la classe.
     *
     * @param student un pointeur vers un élève
     */
    void addStudent(Student *student) { students.push_back(student); }

    /**
     * @brief Renvoie la liste des élèves de la classe.
     *
     * @return la liste des élèves de la classe
     */
    const std::vector<Student *> getStudents() { return students; }

    /**
     * @brief Renvoie le nombre d'élèves dans la classe.
     *
     * @return le nombre d'élèves dans la classe
     */
    int size() { return students.size(); }

    /** @brief Effectue le rendu graphique. */
    void render();

    /**
     * @brief Détruit l'instance de la salle de classe.
     *
     * Cette fonction détruit également l'enseignant ainsi que tous les élèves.
     */
    ~Classroom();

    /**
     * @brief ajoute des notes aux élèves lors d'un clic sur le bouton examen
     */
    void examen() const;
};

#endif /* CLASSROOM_H */
