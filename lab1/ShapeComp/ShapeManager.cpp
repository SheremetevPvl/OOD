#include "../ShapeComp/ShapeManager.h"

void ShapeManager::GetShapes(std::vector<std::unique_ptr<ShapeDecorator>>& Shapes)
{
    shapes = std::move(Shapes);
}

void ShapeManager::DrawShapes(sf::RenderWindow& window) 
{
    for (auto& shape : shapes) 
    {
        shape->draw(window);
    }
}