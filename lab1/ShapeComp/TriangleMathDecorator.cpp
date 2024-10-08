#include "../ShapeComp/TriangleMathDecorator.h"

TriangleMathDecorator::TriangleMathDecorator(std::shared_ptr<ConvexShape> shape) : ShapeDecorator(shape)
{
    CalculateArea();
    CalculatePerimiter();
}

float CalculateLength(const sf::Vector2f p1, const sf::Vector2f p2)
{
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return std::sqrt(dx * dx + dy * dy);
}

//ƒобавить проверку на нахождение на одной пр€мой
void TriangleMathDecorator::CalculatePerimiter()
{
    const sf::Vector2f p1 = std::dynamic_pointer_cast<ConvexShape>(shape)->GetPoint(0);
    const sf::Vector2f p2 = std::dynamic_pointer_cast<ConvexShape>(shape)->GetPoint(1);
    const sf::Vector2f p3 = std::dynamic_pointer_cast<ConvexShape>(shape)->GetPoint(2);
    float a = CalculateLength(p1, p2);
    float b = CalculateLength(p2, p3);
    float c = CalculateLength(p3, p1);
    SetPerimeter(a + b + c);
}

void TriangleMathDecorator::CalculateArea()
{
    const sf::Vector2f p1 = std::dynamic_pointer_cast<ConvexShape>(shape)->GetPoint(0);
    const sf::Vector2f p2 = std::dynamic_pointer_cast<ConvexShape>(shape)->GetPoint(1);
    const sf::Vector2f p3 = std::dynamic_pointer_cast<ConvexShape>(shape)->GetPoint(2);
    float a = CalculateLength(p1, p2);
    float b = CalculateLength(p2, p3);
    float c = CalculateLength(p3, p1);
    float halfPerimeter = (a + b + c) / 2.0f;
    SetArea(std::sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c)));
}