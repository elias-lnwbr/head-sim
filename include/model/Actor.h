#ifndef ACTOR_H
#define ACTOR_H

class Actor {

private:

    std::string name;
    std::string surname;

public:
    Actor() = delete;
    /**
     * @brief Construct un personnage
     * 
     * @param name Prénom du personnage
     * @param surname Nom de famille du personnage
     */
    Actor(std::string name,std::string surname);
    ~Actor();

    /**
     * @brief Renvoie le prénom du personnage.
     * 
     * @return std::string le prénom du personnage
     */
    std::string getName(){ return this->name;}

    /**
     * @brief Modifie le prénom du personnage.
     * 
     * @param name le nouveau prénom du personnage
     */
    void setName(std::string name){ this->name = name;}

    /**
     * @brief Renvoie le nom de famille du personnage
     * 
     * @return std::string le nouveau nom de famille de personnage 
     */
    std::string getSurname(){ return this->surname;}

    /**
     * @brief Set le nom de famille du personnage
     * 
     * @param surname nom de famille du personnage
     */
    void setSurname(std::string surname){ this->surname = surname;}
};

#endif
