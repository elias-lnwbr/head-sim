#ifndef CLASS_H
#define CLASS_H

class Student;
class Teacher;

class Classroom {
private:
    /**
     * @brief Taille maximum de la classe
     * 
     */
    static const int MAX_SIZE = 50;

    /**
     * @brief Elèves de la classe
     * 
     */
    std::vector<Student *> students;

    /**
     * @brief Professeur de la classe
     * 
     */
    Teacher *teacher;
public:
    Classroom() = delete;

    /**
     * @brief Construct a new Classroom object
     * 
     * @param teacher Professeur de la classe
     */
    Classroom(Teacher & teacher);
    ~Classroom();

    /**
     * @brief Get le professeur de la classe
     * 
     * @return Teacher* 
     */
    Teacher* getTeacher(){ return this->teacher;}

    /**
     * @brief Get la liste des élèves
     * 
     * @return std::vector<Student *> Liste des élèves
     */
    std::vector<Student *> getStudents();

    /**
     * @brief Ajoute un élève à la classe
     * 
     * @param student Elève
     */
    void addStudent(Student & student);

    /**
     * @brief Retourne le nombre d'élève dans la classe
     * 
     * @return int nombre d'élève
     */
    int size();
};

#endif
