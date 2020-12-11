#ifndef COMPONENT_H
#define COMPONENT_H

/** @brief Une classe abstraite modélisant un composant graphique. */
class Component {
  public:
    virtual ~Component(){};
    virtual void render() = 0;
};

#endif /* COMPONENT_H */
