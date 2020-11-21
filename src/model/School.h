#ifndef SCHOOL_H
#define SCHOOL_H

class Class;

class School {
private:
    std::string name;
    std::vector<Class *> classes;

public:
    /**
     * @brief Set the Name object
     * 
     * @param name 
     */
    void setName(const std::string &name){ this->name = name; };

    /**
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    std::string getName(){ return this->name; };
};

#endif
