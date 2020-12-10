#ifndef TEXTURABLE_H
#define TEXTURABLE_H

#include <string>

#include <SFML/Graphics.hpp>

#include "view/Component.h"

class Texturable : public Component {
  protected:
    std::string texturePath;
    sf::Texture texture;

  public:
    Texturable(const std::string &filename);
    virtual void render() const;
};

#endif /* TEXTURABLE_H */
