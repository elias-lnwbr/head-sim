#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>

#include "model/Actor.h"

class Teacher : public Actor {
  private:
    /**
     * @brief Niveau de pédagogie du prof
     *
     */
    double pedagogue;

    /**
     * @brief Niveau de méritocratie du professeur
     *
     */
    double meritocratic;

  public:
    /**
     * @brief Construct un nouveau Professeur
     *
     * @param firstname Prénom du professeur
     * @param surname Nom de famille du professeur
     * @param pedagogie Niveau de pédagogie du professeur
     * @param meritocratic Niveau de méritocratie du professeur
     */
    Teacher(const std::string &firstname, const std::string &surname,
            double pedagogie, double meritocratic);

    /**
     * @brief Get le niveau de pédagogie du professeur
     *
     * @return double Niveau de pédagogie du professeur
     */
    double getPedagogue() { return pedagogue; }

    /**
     * @brief Set le niveau de pédagogie du professeur
     *
     * @param pedagogue Niveau de pédagogie du professeur
     */
    void setPedagogue(double pedagogue) { this->pedagogue = pedagogue; }

    /**
     * @brief Get le niveau de méritocratie du professeur
     *
     * @return double
     */
    double getMeritocratic() { return meritocratic; }

    /**
     * @brief Set le niveau de méritocratie du professeur
     *
     * @param meritocratic niveau de méritocratie du professeur
     */
    void setMeritocratic(double meritocratic)
    {
        this->meritocratic = meritocratic;
    }

    /**
     * @brief Affiche la fiche informations du prof.
     */
    void infoSheet() const override;

    /**
     * @brief  Affiche les options disponibles lorsque l'on clique sur le prof.
     */
    void clickPopup() const override;
};

#endif
