#include "../../Shape.h";

float Shape::GetPerimiter() const
{
	return perimeter_;
}

float Shape::GetArea() const
{
	return area_;
}

void Shape::SetArea(float value)
{
	area_ = value;
}

void Shape::SetPerimeter(float value)
{
	perimeter_ = value;
}