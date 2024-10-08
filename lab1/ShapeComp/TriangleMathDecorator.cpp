#include "../ShapeComp/TriangleMathDecorator.h"
#include <algorithm>

const float EPSILON = 1e-6; // Погрешность для сравнения с нулем

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

bool isStraight(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3)
{
    float det = p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
    return std::abs(det) < EPSILON;
}

void TriangleMathDecorator::CalculatePerimiter()
{
    const sf::Vector2f p1 = std::dynamic_pointer_cast<ConvexShape>(shape)->GetPoint(0);
    const sf::Vector2f p2 = std::dynamic_pointer_cast<ConvexShape>(shape)->GetPoint(1);
    const sf::Vector2f p3 = std::dynamic_pointer_cast<ConvexShape>(shape)->GetPoint(2);
    float a = CalculateLength(p1, p2);
    float b = CalculateLength(p2, p3);
    float c = CalculateLength(p3, p1);
    if (isStraight(p1, p2, p3))
    {
        SetPerimeter(std::max({ a, b, c }));
    }
    else
    {
        SetPerimeter(a + b + c);
    }
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