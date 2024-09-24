#include <SFML/Graphics.hpp>
#include "../../Shape.h"
#include "../../CircleShape.h"
#include "../../RectangleShape.h"
#include "../../ConvexShape.h"
#include "../../Control.h"

const std::string INPUT_FILE_NAME = "Input.txt";
const std::string OUTPUT_FILE_NAME = "Output.txt";

int main()
{
    Control controller;
    controller.LoadFile(INPUT_FILE_NAME);
    std::vector<std::unique_ptr<Shape>> shapes = controller.GetShapesFromFile();
    sf::RenderWindow window(sf::VideoMode(800, 400), "Shape constructor");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (int i = 0; i < shapes.size(); i++)
        {
            shapes[i]->draw(window);
        }
        window.display();
    }
    controller.UploadToFile(OUTPUT_FILE_NAME, shapes);
    return 0;
}