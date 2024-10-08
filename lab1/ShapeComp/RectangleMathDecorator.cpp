#include "../ShapeComp/RectangleMathDecorator.h"

RectangleMathDecorator::RectangleMathDecorator(std::shared_ptr<RectangleShape> shape) : ShapeDecorator(shape)
{
    CalculateArea();
    CalculatePerimiter();
}

void RectangleMathDecorator::CalculatePerimiter()
{
    sf::Vector2f size = std::dynamic_pointer_cast<RectangleShape>(shape)->GetSize();
    SetPerimeter(2 * (size.x + size.y));
}

void RectangleMathDecorator::CalculateArea()
{
    sf::Vector2f size = std::dynamic_pointer_cast<RectangleShape>(shape)->GetSize();
    SetArea(size.x * size.y);
}