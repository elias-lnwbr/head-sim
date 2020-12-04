#ifndef SUBJECTH
#define SUBJECTH

class Subject
{

private:
    /**
     * @brief Nom de la matière
     * 
     */
    std::string name;
    
    /**
     * @brief Coefficient de la matière
     * 
     */
    double coeff;

public:
    Subject() = delete;
    /**
     * @brief Construct une Matière
     * 
     * @param name Nom de la Matière
     * @param coeff Coefficient de la matière
     */
    Subject(std::string name, double coeff);
    ~Subject();

    /**
     * @brief Get le nom de la Matière
     * 
     * @return std::string 
     */
    std::string getName(){ return this->name;}

    /**
     * @brief Set le nom de la matière
     * 
     * @param name Nom de la matière
     */
    void setName(std::string name){ this->name;}

    /**
     * @brief Get le coefficient de la matière
     * 
     * @return double coefficient de la matière
     */
    double getCoeff(){ return this->coeff;}

    /**
     * @brief Set le coefficient de la matière
     * 
     * @param coeff coefficient de la matière
     */
    void setCoeff(double coeff){ this->coeff = coeff;}
};


#endif