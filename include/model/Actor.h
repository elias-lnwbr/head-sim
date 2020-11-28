#ifndef ACTOR_H
#define ACTOR_H

class Actor {
private:
    std::string name;

public:
    /**
     * @brief Modifie le nom de l'acteur.
     * 
     * @param name le nouveau nom de l'acteur
     */
    void setName(std::string);

    /**
     * @brief Renvoie le nom de l'acteur.
     * 
     * @return std::string le nom de l'acteur
     */
    std::string getName();
};

#endif
