#pragma once

#include <SFML/Graphics.hpp>
#include "../../Shape.h"

class RectangleShape : public Shape 
{
public:
    RectangleShape(std::vector<Point> points);
    void draw(sf::RenderWindow& window) const override;
protected:
    void CalculatePerimiter() override;
    void CalculateArea() override;
private:
    sf::Vector2f CalculateSize();
    sf::Vector2f position_;
    sf::Vector2f secondPoint_;
    sf::RectangleShape shape_;
};