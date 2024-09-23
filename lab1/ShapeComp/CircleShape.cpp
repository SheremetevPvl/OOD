#include "../../CircleShape.h"

#define _USE_MATH_DEFINES
#include <math.h>

CircleShape::CircleShape(float radius, Point center) : Shape("CIRCLE")
{
    position_.x = center.x;
    position_.y = center.y;
    shape_.setRadius(radius);
    shape_.setPosition(position_);
    shape_.setFillColor(sf::Color::Green);
    CalculateArea();
    CalculatePerimiter();
}

void CircleShape::draw(sf::RenderWindow& window) const
{
    window.draw(shape_);
}

void CircleShape::CalculatePerimiter()
{
    float radius = shape_.getRadius();
    SetPerimeter(2 * M_PI * radius);
}

void CircleShape::CalculateArea()
{
    float radius = shape_.getRadius();
    SetArea(radius * radius * M_PI);
}