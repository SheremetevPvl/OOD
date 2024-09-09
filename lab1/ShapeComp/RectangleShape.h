#pragma once

#include <SFML/Graphics.hpp>
#include "../../Shape.h"

class RectangleShape : public Shape 
{
public:
    RectangleShape(const sf::Vector2f& size);
    void draw() const override;
private:
    sf::RectangleShape shape_;
};