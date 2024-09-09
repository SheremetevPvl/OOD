#pragma once
#include <SFML/Graphics.hpp>
#include "../../Shape.h"

class CircleShape : public Shape {
public:
    CircleShape(unsigned int radius);
    void draw() const override;
private:
    sf::CircleShape shape_;
};