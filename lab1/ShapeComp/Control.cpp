#include "../../Control.h";

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

Point GetPoint(const std::string& input_string)
{
    Point point = {0, 0};
    std::vector<int, int> numbers;
    std::stringstream ss(input_string);
    std::string token;
    // Игнорируем символы до первого числа
    while (std::getline(ss, token, '=')) 
    {
        if (token.find_first_of("0123456789") != std::string::npos) 
        {
            break;
        }
    }
    // Извлекаем числа
    while (std::getline(ss, token, ',')) 
    {
        if (!token.empty() && token.back() == ';') //нужно убрать ';' в последнем токене
        {
            token.pop_back();                 
        }

        try 
        {
            int number = std::stoi(token);
            numbers.push_back(number);
        }
        catch (const std::invalid_argument& e) 
        {
            // Игнорируем нечисловые токены
        }
    }
    if (numbers.size() >= 2)
    {
        point.x = numbers[0];
        point.y = numbers[1];
    }
    else
    {
        std::cout << "point num don`t have 2 values\n";
    }
    return point;
}

int GetNum(const std::string& input_string)
{
    int num(0);
    std::stringstream ss(input_string);
    std::string token;
    while (std::getline(ss, token, '='))
    {
        if (token.find_first_of("0123456789") != std::string::npos)
        {
            break;
        }
    }
    std::getline(ss, token, ',');
    if (!token.empty() && token.back() == ';')
    {
        token.pop_back();
    }
    try
    {
        int number = std::stoi(token);
    }
    catch (const std::invalid_argument& e)
    {
        // Игнорируем нечисловые токены
    }
    return num;
}

std::unique_ptr<Shape> GetTriangle(std::vector<std::string> line)
{
    std::vector<Point> points;
    for (int i = 1; i <= TRIANGLE_ANGLES_QUAL; i++)
    {
        Point point = GetPoint(line[0]);
        points.push_back(point);
        line.erase(line.begin());
    }
    std::unique_ptr<Shape> triangle = std::make_unique<ConvexShape>(points);
    return triangle;
}

std::unique_ptr<Shape> GetRectangle(std::vector<std::string> line)
{
    std::vector<Point> points;
    for (int i = 1; i <= RECTANGLE_ANGLES_QUAL; i++)
    {
        Point point = GetPoint(line[0]);
        points.push_back(point);
        line.erase(line.begin());
    }
    std::unique_ptr<Shape> rectangle = std::make_unique<RectangleShape>(points);
    return rectangle;
}

std::unique_ptr<Shape> GetCircle(std::vector<std::string> line)
{
    Point center = { 0, 0 };
    center = GetPoint(line[0]);
    line.erase(line.begin());
    int radius = GetNum(line[0]);
    std::unique_ptr<Shape> circle = std::make_unique<CircleShape>(radius, center);
    return circle;
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

std::vector<std::unique_ptr<Shape>> Control::GetShapesFromFile()
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
                shapes.push_back(shape);
            }
        }
    }
    return shapes;
}

void Control::UnloadToFile(const std::string& filename, std::vector<std::unique_ptr<Shape>> shapes)
{
    std::ofstream file(filename);
    // Проверяем, удалось ли открыть файл
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    // Записываем содержимое вектора в файл
    for (const auto& shape : shapes) 
    {
        file << "name" << std::endl;
    }

    // Закрываем файл
    file.close();
}