#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Component.h"

class MainView : public Component
{
  private:
    std::vector<sf::Texture *> classrooms;

  public:
    MainView();
    ~MainView();

    void render() const;
};

#endif /* MAINVIEW_H */
