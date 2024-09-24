#pragma once

#include <SFML/Graphics.hpp>
#include "../../Shape.h"
#include "vector"

class ConvexShape : public Shape 
{
public:
    ConvexShape(std::vector<Point> points);
    void draw(sf::RenderWindow& window) const override;
protected:
    void CalculatePerimiter() override;
    void CalculateArea() override;
private:
    sf::ConvexShape shape_;
    std::vector<sf::Vector2f> points_;
};