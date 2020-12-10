#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "model/School.h"
#include "view/Component.h"

class MainView : public Component {
  private:
    School *school;

  public:
    MainView();
    ~MainView();
    void render() const;
};

#endif /* MAINVIEW_H */
