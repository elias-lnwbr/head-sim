#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>
#include <vector>

#include "model/Classroom.h"
#include "view/Component.h"

class School : public Component {
  private:
    /** @brief Nom de l'école */
    std::string name;

    /** @brief Classes dans l'école */
    std::vector<Classroom *> classrooms;

  public:
    School(const std::string &name);
    ~School();

    /**
     * @brief Set le nom de l'école
     *
     * @param name Nom de l'école
     */
    void setName(const std::string &name) { this->name = name; }

    /**
     * @brief Get le nom de l'école
     *
     * @return std::string Nom de l'école
     */
    std::string getName() { return this->name; }

    /**
     * @brief Ajoute une classe à l'école
     *
     * @param classe Classe à ajouter
     */
    void addClass(Classroom *classe) { classrooms.push_back(classe); }

    /**
     * @brief Get the Class From Index object
     *
     * @param index
     * @return Classroom*
     */
    Classroom *getClassFromIndex(int index) { return classrooms[index]; }

    void render() const;
};

#endif
