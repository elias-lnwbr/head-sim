#ifndef STUDENT_H
#define STUDENT_H

#include <map>
#include <vector>

#include "model/Actor.h"
#include "model/Classroom.h"
#include "model/Subject.h"

class Classroom;

class Student : public Actor {
  private:
    /** @brief Classe de l'élève */
    Classroom *classroom;

    /** @brief Notes de l'élève */
    std::map<Subject *, std::vector<double>> grades;

    /** @brief Humeur de l'élève */
    double mood;

    /** @brief Motivation de l'élève */
    double motivation;

    /** @brief Qualité de l'élève */
    double skill;

  public:
    /**
     * @brief Construct a new Student object
     *
     * @param name prénom de l'élève
     * @param surname nom de famille de l'élève
     * @param mood Humeur de l'élève
     * @param motivation Motivation de l'élève
     * @param skill Qualité de l'élève
     */
    Student(const std::string &name, const std::string &surname, double mood,
            double motivation, double skill);
    ~Student();

    /**
     * @brief Retourne l'objet classroom
     *
     * @return Classroom  Classe de l'élève
     */
    Classroom *getClassroom() { return classroom; }

    /**
     * @brief Set l'objet classroom
     *
     * @param classroom Classe de l'élève
     */
    void setClassroom(Classroom *classroom) { this->classroom = classroom; }

    /**
     * @brief Get l'humeur de l'élève
     *
     * @return double humeur de l'élève
     */
    double getMood() { return this->mood; }

    /**
     * @brief Set l'humeur de l'élève
     *
     * @param mood nouvelle humeur de l'élève
     */
    void setMood(double mood) { this->mood = mood; }

    /**
     * @brief Get la motivation de l'élève
     *
     * @return double motivation de l'élève
     */
    double getMotivation() { return motivation; }

    /**
     * @brief Set la motivation de l'élève
     *
     * @param motivation nouvelle motivation de l'élève
     */
    void setMotivation(double motivation) { this->motivation = motivation; }

    /**
     * @brief Get la Qualité de l'élève
     *
     * @return double Qualité de l'élève
     */
    double getSkill() { return skill; }

    /**
     * @brief Set la qualité de l'élève
     *
     * @param skill nouvelle qualité de l'élève
     */
    void setSkill(double skill) { this->skill = skill; }

    /**
     * @brief Ajoute une note à l'élève
     *
     * @param subject Matière
     * @param grade Note
     */
    void addGrades(Subject *subject, double grade);

    void render() const;
};

#endif
