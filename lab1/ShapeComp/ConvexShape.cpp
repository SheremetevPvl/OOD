#include "../ShapeComp/ConvexShape.h"

std::vector<sf::Vector2f>GetPoints(std::vector<Point> inputPoints)
{
    int size = inputPoints.size();
    std::vector<sf::Vector2f> points;
    for (int i = 0; i < size; i++)
    {
        sf::Vector2f point;
        point.x = inputPoints[i].x;
        point.y = inputPoints[i].y;
        points.push_back(point);
    }
    return points;
}

ConvexShape::ConvexShape(std::vector<Point> inputPoints) : Shape("TRIANGLE")
{
    points_ = GetPoints(inputPoints);
    int size = points_.size();
    shape_.setPointCount(size);
    for (int i = 0; i < size; i++)
    {
        shape_.setPoint(i, points_[i]);
    }
    shape_.setFillColor(sf::Color::Blue);
}

void ConvexShape::draw(sf::RenderWindow& window) const
{
    window.draw(shape_);
}

sf::Vector2f ConvexShape::GetPoint(int index)
{
    return shape_.getPoint(index);
}