#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>
#include <vector>

class Classroom;

class School {
private:
    /**
     * @brief Nom de l'école
     * 
     */
    std::string name;

    /**
     * @brief Classes dans l'école
     * 
     */
    std::vector<Classroom *> classes;

public:
    School() = delete;
    School(std::string name);
    ~School();
    /**
     * @brief Set le nom de l'école
     * 
     * @param name Nom de l'école
     */
    void setName(const std::string &name){ this->name = name; };

    /**
     * @brief Get le nom de l'école
     * 
     * @return std::string Nom de l'école
     */
    std::string getName(){ return this->name; };

    /**
     * @brief Ajoute une classe à l'école
     * 
     * @param classe Classe à ajouter
     */
    void addClass(Classroom* classe){ classes.push_back(classe);};
};

#endif
