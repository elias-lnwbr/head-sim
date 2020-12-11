#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>

/**
 * @brief Modélise une matière.
 */
class Subject {
  private:
    /** @brief Nom de la matière. */
    std::string name;

    /** @brief Coefficient de la matière. */
    double coeff;

  public:
    /**
     * @brief Crée une matière.
     *
     * @param name  le nom de la matière
     * @param coeff le coefficient de la matière
     */
    Subject(const std::string &name, double coeff)
      : name(name)
      , coeff(coeff)
    {
    }

    /**
     * @brief Modifie le nom de la matière.
     *
     * @param name le nouveau nom de la matière
     */
    void setName(const std::string &name) { this->name = name; }

    /**
     * @brief Renvoie le nom de la matière.
     *
     * @return le nom de la matière
     */
    const std::string &getName() { return name; }

    /**
     * @brief Modifie le coefficient de la matière.
     *
     * @param coeff le nouveau coefficient de la matière
     */
    void setCoeff(double coeff) { this->coeff = coeff; }

    /**
     * @brief Renvoie le coefficient de la matière.
     *
     * @return le coefficient de la matière
     */
    double getCoeff() { return coeff; }
};

#endif /* SUBJECT_H */
