#include "../../RectangleShape.h"
#include <iostream>

RectangleShape::RectangleShape(std::vector<Point> points) : Shape("RECTANGLE")
{
    try
    {
        if (points.size() < 2)
        {
            throw std::runtime_error("No points at rectangle");
        }
        else
        {
            position_.x = points[0].x;
            position_.y = points[0].y;
            secondPoint_.x = points[1].x;
            secondPoint_.y = points[1].y;
            shape_.setPosition(position_);
            shape_.setSize(CalculateSize());
        }
       
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    shape_.setFillColor(sf::Color::Red);
    CalculateArea();
    CalculatePerimiter();
}

sf::Vector2f RectangleShape::CalculateSize()
{
    sf::Vector2f size(secondPoint_.x - position_.x, secondPoint_.y - position_.y);
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