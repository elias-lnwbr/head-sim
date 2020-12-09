#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <SFML/Graphics.hpp>

#include "Component.h"

class MainView : public Component {
private:
    sf::Texture classroom;

public:
    MainView();

    void render() const;
};

#endif /* MAINVIEW_H */
