#pragma once
#include "../ShapeComp/ConvexShape.h"
#include "../ShapeComp/ShapeDecorator.h"

class TriangleMathDecorator : public ShapeDecorator {
public:
    TriangleMathDecorator(std::shared_ptr<ConvexShape> shape);
protected:
    void CalculatePerimiter() override;
    void CalculateArea() override;
};