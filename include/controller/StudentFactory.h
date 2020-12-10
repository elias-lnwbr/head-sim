#ifndef STUDENTFACTORY
#define STUDENTFACTORY

#include <istream>
#include <map>
#include <string>
#include <vector>

#include "Game.h"
#include "model/Student.h"

/** @brief Classe permettant de génerer des noms pour les élèves */
class StudentFactory{
private:
    /**
     * @brief liste de élèves
     * 
     */
    static std::vector<Student *> studentFactory;
    /**
     * @brief nom du fichier
     * 
     */
    static std::string filename;
    /**
     * @brief Get the Next Line And Split Into Tokens object
     * 
     * @param str input stream
     * @return std::vector<std::string> ligne de string contenant les infos
     */
    static std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& stream);
    
public:
    StudentFactory() = delete;
    ~StudentFactory();

    static void loadStudentFactory();
    static Student * getRandomStudent();

};


#endif /* STUDENTFACTORY_H */