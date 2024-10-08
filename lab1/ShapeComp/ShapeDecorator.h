#pragma once
#include "../ShapeComp/Shape.h"

class ShapeDecorator : public Shape
{
public:
    ShapeDecorator(std::shared_ptr<Shape> shape);
    void draw(sf::RenderWindow& window) const override;
    float GetPerimiter() const;
    float GetArea() const;
protected:
    virtual void CalculatePerimiter() = 0;
    virtual void CalculateArea() = 0;
    void SetPerimeter(float value);
    void SetArea(float value);
    std::shared_ptr<Shape> shape;
private:
    float perimeter_ = 0.0;
    float area_ = 0.0;
};