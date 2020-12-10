#ifndef ACTOR_H
#define ACTOR_H

#include <string>

#include "view/Texturable.h"

class Actor : public Texturable {
  private:
    std::string firstname;
    std::string surname;

  public:
    /**
     * @brief Crée un personnage.
     *
     * @param firstname        le prénom du personnage
     * @param surname     le nom de famille du personnage
     * @param texturePath le chemin du fichier de texture
     */
    Actor(const std::string &firstname, const std::string &surname,
          const std::string &texturePath);

    /**
     * @brief Renvoie le prénom du personnage.
     *
     * @return std::string le prénom du personnage
     */
    const std::string &getFirstName() const { return firstname; }

    /**
     * @brief Modifie le prénom du personnage.
     *
     * @param name le nouveau prénom du personnage
     */
    void setFirstName(const std::string &firstname)
    {
        this->firstname = firstname;
    }

    /**
     * @brief Renvoie le nom de famille du personnage
     *
     * @return std::string le nouveau nom de famille de personnage
     */
    const std::string &getSurname() const { return surname; }

    /**
     * @brief Modifie le nom de famille du personnage
     *
     * @param surname nom de famille du personnage
     */
    void setSurname(const std::string &surname) { this->surname = surname; }
};

#endif
