#ifndef COMPONENT_H
#define COMPONENT_H

/** @brief Une classe abstraite modélisant un composant graphique. */
class Component {
public:
    virtual void render() const = 0;
};

#endif /* COMPONENT_H */
