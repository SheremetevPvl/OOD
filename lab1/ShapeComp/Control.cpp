#include "../../Control.h"

const char DELIMITER = ' ';
const int TRIANGLE_ANGLES_QUAL = 3;
const int RECTANGLE_ANGLES_QUAL = 2;

void Control::LoadFile(const std::string& filename)
{
    file_ = std::ifstream(filename);
    if (!file_.is_open()) 
    {
        std::cerr << "File not found: " << filename << std::endl;
    }
}

Point GetPoint(const std::string& inputString)
{
    Point point = {0.0f, 0.0f};
    std::vector<float> numbers;
    std::stringstream string(inputString);
    std::string token;
    std::getline(string, token, '=');
    while (std::getline(string, token, ',')) 
    {
        if (!token.empty() && token.back() == ';') //нужно убрать ';' в последнем токене
        {
            token.pop_back();
        }
        try 
        {
            float number = std::stoi(token);
            numbers.push_back(number);
        }
        catch (const std::invalid_argument& e) 
        {
            std::cerr << "Not num at point: " << token << std::endl;
        }
    }
    if (numbers.size() == 2)
    {
        point.x = numbers[0];
        point.y = numbers[1];
    }
    return point;
}

float GetNum(const std::string& inputString)
{
    float number(0);
    std::stringstream string(inputString);
    std::string token;
    std::getline(string, token, '=');
    std::getline(string, token);
    if (!token.empty() && token.back() == ';')
    {
        token.pop_back();
    }
    try
    {
        number = std::stoi(token);
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Not num value: " << token << std::endl;
    }
    return number;
}

std::unique_ptr<Shape> GetTriangle(std::vector<std::string> params)
{
    std::vector<Point> points;
    for (int i = 1; i <= TRIANGLE_ANGLES_QUAL; i++)
    {
        Point point = GetPoint(params[0]);
        points.push_back(point);
        if (!params.empty())
        {
            params.erase(params.begin());
        }
    }
    return std::make_unique<ConvexShape>(points);
}

std::unique_ptr<Shape> GetRectangle(std::vector<std::string> params)
{
    std::vector<Point> points;
    for (int i = 1; i <= RECTANGLE_ANGLES_QUAL; i++)
    {
        Point point = GetPoint(params[0]);
        points.push_back(point);
        if (!params.empty())
        {
            params.erase(params.begin());
        }
    }
    return std::make_unique<RectangleShape>(points);
}

std::unique_ptr<Shape> GetCircle(std::vector<std::string> params)
{
    Point center = { 0, 0 };
    center = GetPoint(params[0]);
    params.erase(params.begin());
    float radius = GetNum(params[0]);
    return std::make_unique<CircleShape>(radius, center);
}

std::vector<std::string> Split(const std::string& str, char delimiter) 
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) 
    {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<std::unique_ptr<Shape>>Control::GetShapesFromFile()
{
    std::map<std::string, std::function<std::unique_ptr<Shape>(const std::vector<std::string>&)>> shapesMap = 
    {
        {"TRIANGLE:", GetTriangle},
        {"RECTANGLE:", GetRectangle},
        {"CIRCLE:", GetCircle}
    };
    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;
    while (std::getline(file_, line))
    {
        std::vector<std::string> words = Split(line, DELIMITER);
        if (!words.empty())
        {
            std::string shapeName = words[0];
            words.erase(words.begin());
            if (shapesMap.find(shapeName) != shapesMap.end())
            {
                std::unique_ptr<Shape> shape = shapesMap[shapeName](words);
                shapes.push_back(std::move(shape));
            }
        }
    }
    return shapes;
}

void Control::UploadToFile(const std::string& filename, std::vector<std::unique_ptr<Shape>>& shapes)
{
    std::ofstream file(filename);
    if (!file.is_open()) 
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    for (const auto& shape : shapes) 
    {
        file << shape->GetName() << ": " << "P= " << shape->GetPerimiter() << " S= " << shape->GetArea() << "\n";
    }
    file.close();
}