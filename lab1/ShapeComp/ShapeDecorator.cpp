#include "../ShapeComp/ShapeDecorator.h"

ShapeDecorator::ShapeDecorator(std::shared_ptr<Shape> shape) : Shape(shape->GetName()), shape(shape) {}

float ShapeDecorator::GetPerimiter() const
{
	return perimeter_;
}

float ShapeDecorator::GetArea() const
{
	return area_;
}

void ShapeDecorator::SetPerimeter(float value)
{
	perimeter_ = value;
}

void ShapeDecorator::SetArea(float value)
{
	area_ = value;
}

void ShapeDecorator::draw(sf::RenderWindow& window) const
{
	return shape->draw(window);
}