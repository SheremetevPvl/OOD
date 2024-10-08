#include "../ShapeComp/Shape.h";

Shape::Shape(const std::string& name) : shapeName(name) {}

std::string Shape::GetName()
{
	return shapeName;
}