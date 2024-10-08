#pragma once

#include <SFML/Graphics.hpp>
#include "../ShapeComp/Shape.h"
#include "vector"
#include <iostream>

class ConvexShape : public Shape 
{
public:
    ConvexShape(std::vector<Point> points);
    void draw(sf::RenderWindow& window) const override;
    sf::Vector2f GetPoint(int index);
private:
    sf::ConvexShape shape_;
    std::vector<sf::Vector2f> points_;
};