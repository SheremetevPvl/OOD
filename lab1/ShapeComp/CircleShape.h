#pragma once
#include <SFML/Graphics.hpp>
#include "../ShapeComp/Shape.h"

class CircleShape : public Shape 
{
public:
    CircleShape(float radius, Point center);
    void draw(sf::RenderWindow& window) const override;
    float GetRadius() const;
private:
    sf::CircleShape shape_;
    sf::Vector2f position_;
};