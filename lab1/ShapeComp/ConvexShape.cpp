#include "../../ConvexShape.h"

ConvexShape::ConvexShape(std::vector<Point>& points) : shape_(points.size()) 
{
    int size = points.size();
    for (int i = 0; i < size; i++)
    {
        shape_.setPoint(i, sf::Vector2f(points[i].x, points[i].y));
    }
    if (size != 0)
    {
        shape_.setPosition(points[0].x, points[0].y);
    }
    CalculatePerimiter();
    CalculateArea(); 
}

void ConvexShape::draw(sf::RenderWindow& window) const
{
    window.draw(shape_);
}

float CalculateLength(const sf::Vector2f& p1, const sf::Vector2f& p2)
{
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void ConvexShape::CalculatePerimiter()
{
    const sf::Vector2f& p1 = shape_.getPoint(0);
    const sf::Vector2f& p2 = shape_.getPoint(1);
    const sf::Vector2f& p3 = shape_.getPoint(2);
    float a = CalculateLength(p1, p2);
    float b = CalculateLength(p2, p3);
    float c = CalculateLength(p3, p1);
    SetPerimeter(a + b + c);
}

void ConvexShape::CalculateArea()
{
    const sf::Vector2f& p1 = shape_.getPoint(0);
    const sf::Vector2f& p2 = shape_.getPoint(1);
    const sf::Vector2f& p3 = shape_.getPoint(2);
    float a = CalculateLength(p1, p2);
    float b = CalculateLength(p2, p3);
    float c = CalculateLength(p3, p1);
    float halfPerimeter = (a + b + c) / 2.0f;
    SetArea(std::sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c)));
}