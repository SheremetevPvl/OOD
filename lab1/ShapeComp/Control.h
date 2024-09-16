#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <functional>
#include <vector>

#include "../../Shape.h"
#include "../../CircleShape.h"
#include "../../ConvexShape.h"
#include "../../RectangleShape.h"

class Control
{
public:
	void LoadFile(const std::string& filename);
	std::vector<std::unique_ptr<Shape>> GetShapesFromFile();
	void UnloadToFile(const std::string& filename, std::vector<std::unique_ptr<Shape>> shapes);
private:
	std::ifstream file_;
};