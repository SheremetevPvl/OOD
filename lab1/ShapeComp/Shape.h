#pragma once
#include <SFML/Graphics.hpp>

struct Point
{
    int x;
    int y;
};

class Shape 
{
public:
    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual ~Shape() {};
    float GetPerimiter() const;
    float GetArea() const;
protected:
    virtual void CalculatePerimiter() = 0;
    virtual void CalculateArea() = 0;
    void SetPerimeter(float value);
    void SetArea(float value);
private:
    float perimeter_ = 0.0;
    float area_ = 0.0;
};