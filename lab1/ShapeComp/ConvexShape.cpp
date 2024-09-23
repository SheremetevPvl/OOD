#include "../../ConvexShape.h"
#include <iostream>

std::vector<sf::Vector2f>GetPoints(std::vector<Point> inputPoints)
{
    int size = inputPoints.size();
    std::vector<sf::Vector2f> points;
    for (int i = 0; i < size; i++)
    {
        sf::Vector2f point;
        point.x = inputPoints[i].x;
        point.y = inputPoints[i].y;
        points.push_back(point);
    }
    return points;
}

ConvexShape::ConvexShape(std::vector<Point> inputPoints) : Shape("TRIANGLE")
{
    points_ = GetPoints(inputPoints);
    int size = points_.size();
    shape_.setPointCount(size);
    for (int i = 0; i < size; i++)
    {
        shape_.setPoint(i, points_[i]);
    }
    shape_.setFillColor(sf::Color::Blue);
    CalculatePerimiter();
    CalculateArea(); 
}

void ConvexShape::draw(sf::RenderWindow& window) const
{
    window.draw(shape_);
}

float CalculateLength(const sf::Vector2f p1, const sf::Vector2f p2)
{
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return std::sqrt(dx * dx + dy * dy);
}

void ConvexShape::CalculatePerimiter()
{
    const sf::Vector2f p1 = shape_.getPoint(0);
    const sf::Vector2f p2 = shape_.getPoint(1);
    const sf::Vector2f p3 = shape_.getPoint(2);
    float a = CalculateLength(p1, p2);
    float b = CalculateLength(p2, p3);
    float c = CalculateLength(p3, p1);
    SetPerimeter(a + b + c);
}

void ConvexShape::CalculateArea()
{
    const sf::Vector2f p1 = shape_.getPoint(0);
    const sf::Vector2f p2 = shape_.getPoint(1);
    const sf::Vector2f p3 = shape_.getPoint(2);
    float a = CalculateLength(p1, p2);
    float b = CalculateLength(p2, p3);
    float c = CalculateLength(p3, p1);
    float halfPerimeter = (a + b + c) / 2.0f;
    SetArea(std::sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c)));
}