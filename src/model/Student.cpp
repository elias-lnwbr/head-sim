#include <assert.h>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "model/Actor.h"
#include "model/Student.h"
#include "view/InfoSheet.h"

Student::Student(const std::string &firstname, const std::string &surname,
                 double mood, double motivation, double skill,
                 const std::string &texturePath)
  : Actor(firstname, surname, texturePath)
  , mood(mood)
  , motivation(motivation)
  , skill(skill)
{
}

void
Student::addGrades(Subject *subject, double grade)
{
    if (grades.count(subject) > 0)
        grades.at(subject).push_back(grade);
    else {
        grades.emplace(subject, std::vector<double>());
        addGrades(subject, grade);
    }
}

void
Student::clickPopup()
{
    if (ImGui::MenuItem("Afficher fiche information")) {
        infoSheet();
    }
    if (ImGui::MenuItem("Interroger")) {
    }
    if (ImGui::MenuItem("Lancer une craie")) {
    }
    if (ImGui::MenuItem("Envoyer au coin")) {
    }
}

void
Student::infoSheet()
{
    Game::addComponent(new InfoSheet(this));
}

double
Student::moyenneGenerale() const
{
    double res = 0;
    double sommeCoeff = 0;
    for (const auto &kv : grades) {
        sommeCoeff += kv.first->getCoeff();
        res += moyenneMatiere(kv.first) * kv.first->getCoeff();
    }
    return res / sommeCoeff; // on divise la moyenne par la somme des coeffs
}

double
Student::moyenneMatiere(Subject *subject) const
{
    assert(grades.count(subject) > 0);

    double moyMatiere = 0;

    const std::vector<double> &notes = grades.at(subject);
    std::vector<double>::size_type vecsize = notes.size();

    for (std::vector<double>::size_type i = 0; i < vecsize; i++)
        moyMatiere += notes[i]; // somme des notes de la matiere

    moyMatiere /= vecsize; // divise par le nombre de notes
    return moyMatiere;
}
