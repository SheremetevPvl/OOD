#pragma once
#include <SFML/Graphics.hpp>
#include "../../Shape.h"

class CircleShape : public Shape 
{
public:
    CircleShape(float radius, Point center);
    void draw(sf::RenderWindow& window) const override;
protected:
    void CalculatePerimiter() override;
    void CalculateArea() override;
private:
    sf::CircleShape shape_;
    sf::Vector2f position_;
};