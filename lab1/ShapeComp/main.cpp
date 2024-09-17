#include <SFML/Graphics.hpp>
#include "../../Shape.h";
#include "../../Control.h"

const std::string INPUT_FILE_NAME = "Input.txt";
const std::string OUTPUT_FILE_NAME = "Output.txt";

int main()
{
   /* sf::RenderWindow window(sf::VideoMode(1000, 600), "Shape redactor");
    Control controller;
    controller.LoadFile(INPUT_FILE_NAME);
    std::vector<std::unique_ptr<Shape>> shapes = controller.GetShapesFromFile();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (const auto& shape : shapes)
        {
            shape->draw(window);
        }
        window.display();
    }*/
    // controller.UnloadToFile(OUTPUT_FILE_NAME, shapes);
    return 0;
}