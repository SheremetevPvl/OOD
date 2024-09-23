#include "../../Shape.h";

float Shape::GetPerimiter() const
{
	return perimeter_;
}

float Shape::GetArea() const
{
	return area_;
}

void Shape::SetPerimeter(float value)
{
	perimeter_ = value;
}

void Shape::SetArea(float value)
{
	area_ = value;
}

std::string Shape::GetName()
{
	return shapeName;
}