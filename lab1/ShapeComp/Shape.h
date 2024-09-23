#pragma once
#include <SFML/Graphics.hpp>

struct Point
{
    float x;
    float y;
};

class Shape 
{
public:
    Shape(const std::string& name) : shapeName(name) {}
    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual ~Shape() = default;
    float GetPerimiter() const;
    float GetArea() const;
    std::string GetName();
protected:
    virtual void CalculatePerimiter() = 0;
    virtual void CalculateArea() = 0;
    void SetPerimeter(float value);
    void SetArea(float value);
    std::string shapeName;
private:
    float perimeter_ = 0.0;
    float area_ = 0.0;
};