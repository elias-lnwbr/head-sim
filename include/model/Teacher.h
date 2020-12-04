#ifndef TEACHER_H
#define TEACHER_H

class Actor;

class Teacher : Actor {

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
    double meritrocratic;

public:
    Teacher() = delete;
    /**
     * @brief Construct un nouveau Professeur
     * 
     * @param name Prénom du professeur
     * @param surname Nom de famille du professeur
     * @param pedagogie Niveau de pédagogie du professeur
     * @param meritocratic Niveau de méritocratie du professeur
     */
    Teacher(std::string name, std::string surname, double pedagogie, double meritocratic);
    ~Teacher();

    /**
     * @brief Get le niveau de pédagogie du professeur
     * 
     * @return double Niveau de pédagogie du professeur
     */
    double getPedagogue(){ return this->pedagogue;}
    
    /**
     * @brief Set le niveau de pédagogie du professeur
     * 
     * @param pedagogue Niveau de pédagogie du professeur
     */
    void setPedagogue(double pedagogue){ this->pedagogue = pedagogue;}

    /**
     * @brief Get le niveau de méritocratie du professeur
     * 
     * @return double 
     */
    double getMeritocratic(){ return this->meritocratic;}
    
    /**
     * @brief Set le niveau de méritocratie du professeur
     * 
     * @param meritocratic niveau de méritocratie du professeur
     */
    void setMeritocratic(double meritocratic){ this->meritrocratic = meritrocratic;}

};

#endif
