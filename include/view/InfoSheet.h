#ifndef INFO_SHEET_H
#define INFO_SHEET_H

#include "model/Student.h"
#include "view/Component.h"

/** @brief Une fiche d'information d'un personnage. */
class InfoSheet : public Component {
  private:
    Student *student;

  public:
    InfoSheet(Student *student)
      : student(student)
    {
    }
    void render();
};

#endif /* INFO_SHEET_H */
