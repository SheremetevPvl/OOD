#pragma once
#include "../ShapeComp/CircleShape.h"
#include "../ShapeComp/ShapeDecorator.h"

class CircleMathDecorator : public ShapeDecorator {
public:
    CircleMathDecorator(std::shared_ptr<CircleShape> shape);
protected:
    void CalculatePerimiter() override;
    void CalculateArea() override;
};