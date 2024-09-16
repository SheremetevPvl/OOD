#include "../../RectangleShape.h"

RectangleShape::RectangleShape(std::vector<Point> points) : shape_(size_)
{
    bottomLeft_ = sf::Vector2f(points[0].x, points[0].y);
    topRight_ = sf::Vector2f(points[1].x, points[1].y);
    shape_.setPosition(bottomLeft_);
    CalculateArea();
    CalculatePerimiter();
}

sf::Vector2f RectangleShape::CalculateSize()
{
    sf::Vector2f size(topRight_.x - bottomLeft_.x, bottomLeft_.y - topRight_.y);
    return size;
}

void RectangleShape::draw(sf::RenderWindow& window) const 
{
    window.draw(shape_);
}

void RectangleShape::CalculatePerimiter()
{
    sf::Vector2f size = shape_.getSize();
    SetPerimeter(2 * (size.x + size.y));
}

void RectangleShape::CalculateArea()
{
    sf::Vector2f size = shape_.getSize();
    SetArea(size.x * size.y);
}