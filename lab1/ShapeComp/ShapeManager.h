#pragma once
#include <vector>
#include "../ShapeComp/ShapeDecorator.h"

class ShapeManager
{
public:
    void GetShapes(std::vector<std::unique_ptr<ShapeDecorator>>& Shapes);
    void DrawShapes(sf::RenderWindow& window);
private:
    std::vector<std::unique_ptr<ShapeDecorator>> shapes;
};