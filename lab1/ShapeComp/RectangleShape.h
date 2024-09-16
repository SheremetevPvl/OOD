#pragma once

#include <SFML/Graphics.hpp>
#include "../../Shape.h"

class RectangleShape : public Shape 
{
public:
    //RectangleShape(sf::Vector2f& bottomLeft, sf::Vector2f& topRight);
    RectangleShape(std::vector<Point> points);
    void draw(sf::RenderWindow& window) const override;
protected:
    void CalculatePerimiter() override;
    void CalculateArea() override;
private:
    sf::Vector2f CalculateSize();
    sf::Vector2f bottomLeft_;
    sf::Vector2f topRight_;
    sf::RectangleShape shape_;
    sf::Vector2f size_ = CalculateSize();
};