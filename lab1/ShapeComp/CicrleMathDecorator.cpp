#include "../ShapeComp/CircleMathDecorator.h"

#define _USE_MATH_DEFINES
#include <math.h>

CircleMathDecorator::CircleMathDecorator(std::shared_ptr<CircleShape> shape) : ShapeDecorator(shape)
{
    CalculatePerimiter();
    CalculateArea();
}

void CircleMathDecorator::CalculatePerimiter()
{
    float radius = std::dynamic_pointer_cast<CircleShape>(shape)->GetRadius();
    SetPerimeter(2 * M_PI * radius);
}

void CircleMathDecorator::CalculateArea()
{
    float radius = std::dynamic_pointer_cast<CircleShape>(shape)->GetRadius();;
    SetArea(radius * radius * M_PI);
}