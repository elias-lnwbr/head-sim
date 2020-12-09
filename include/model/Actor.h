#ifndef ACTOR_H
#define ACTOR_H

#include <string>

class Actor
{
  private:
    std::string name;
    std::string surname;

  public:
    /**
     * Crée un personnage.
     *
     * @param name    Prénom du personnage
     * @param surname Nom de famille du personnage
     */
    Actor(const std::string &name, const std::string &surname);
    ~Actor();

    /**
     * @brief Renvoie le prénom du personnage.
     *
     * @return std::string le prénom du personnage
     */
    const std::string &getName() const { return name; }

    /**
     * @brief Modifie le prénom du personnage.
     *
     * @param name le nouveau prénom du personnage
     */
    void setName(const std::string &name) { this->name = name; }

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
