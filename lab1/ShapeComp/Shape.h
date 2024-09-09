#pragma once

class Shape 
{
public:
    virtual void draw() const = 0;
    virtual ~Shape() {};
    virtual unsigned int getPerimiter();
    virtual unsigned int getSquare();
};