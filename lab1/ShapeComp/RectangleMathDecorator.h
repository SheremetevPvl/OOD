#pragma once
#include "../ShapeComp/ShapeDecorator.h"
#include "../ShapeComp/RectangleShape.h"

class RectangleMathDecorator : public ShapeDecorator {
public:
    RectangleMathDecorator(std::shared_ptr<RectangleShape> shape);
protected:
    void CalculatePerimiter() override;
    void CalculateArea() override;
};