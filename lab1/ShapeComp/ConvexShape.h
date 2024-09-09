#pragma once

#include <SFML/Graphics.hpp>
#include "../../Shape.h"

class ConvexShape : public Shape {
public:
    ConvexShape(unsigned int pointCount) : shape_(pointCount) {}
    void draw() const override {
        // Реализация отрисовки выпуклой фигуры
    }
private:
    sf::ConvexShape shape_;
};