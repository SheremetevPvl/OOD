#pragma once

#include <SFML/Graphics.hpp>
#include "../../Shape.h"
#include "vector"

class ConvexShape : public Shape {
public:
    ConvexShape(std::vector<Point>& points) : shape_(points.size()) {}
    void draw(sf::RenderWindow& window) const override;
protected:
    void CalculatePerimiter() override;
    void CalculateArea() override;
private:
    sf::ConvexShape shape_;
};