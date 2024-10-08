#pragma once

#include <SFML/Graphics.hpp>
#include "../ShapeComp/Shape.h"

class RectangleShape : public Shape 
{
public:
    RectangleShape(std::vector<Point> points);
    void draw(sf::RenderWindow& window) const override;
    sf::Vector2f GetSize() const;
private:
    sf::Vector2f CalculateSize();
    sf::Vector2f position_;
    sf::Vector2f secondPoint_;
    sf::RectangleShape shape_;
};