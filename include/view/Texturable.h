#ifndef TEXTURABLE_H
#define TEXTURABLE_H

#include <string>

#include <SFML/Graphics.hpp>

#include "controller/Game.h"
#include "view/Component.h"

class Texturable : public Component {
  protected:
    std::string texturePath;
    sf::Texture texture;

  public:
    Texturable(const std::string &filename);
    virtual void render() const;
    virtual const std::string &getTexturePath() const;
};

#endif /* TEXTURABLE_H */
