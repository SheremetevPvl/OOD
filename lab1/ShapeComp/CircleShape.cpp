#include "../../CircleShape.h"

#define _USE_MATH_DEFINES
#include <math.h>

CircleShape::CircleShape(unsigned int radius, Point center) : shape_(radius) 
{
    posX_ = center.x;
    posY_ = center.y;
    shape_.setPosition(posX_, posY_);
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