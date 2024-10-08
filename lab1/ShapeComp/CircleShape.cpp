#include "../ShapeComp/CircleShape.h"

CircleShape::CircleShape(float radius, Point center) : Shape("CIRCLE")
{
    position_.x = center.x;
    position_.y = center.y;
    shape_.setRadius(radius);
    shape_.setPosition(position_);
    shape_.setFillColor(sf::Color::Green);
}

void CircleShape::draw(sf::RenderWindow& window) const
{
    window.draw(shape_);
}

float CircleShape::GetRadius() const 
{
    return shape_.getRadius();
}
