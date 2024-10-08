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
    Shape(const std::string& name);
    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual ~Shape() = default;
    std::string GetName();
protected:
    std::string shapeName;
};