#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <functional>
#include <vector>

#include "../ShapeComp/Shape.h"
#include "../ShapeComp/CircleShape.h"
#include "../ShapeComp/ConvexShape.h"
#include "../ShapeComp/RectangleShape.h"
#include "../ShapeComp/CircleMathDecorator.h"
#include "../ShapeComp/TriangleMathDecorator.h"
#include "../ShapeComp/RectangleMathDecorator.h"

class Control
{
public:
	void LoadFile(const std::string& filename);
	std::vector<std::unique_ptr<ShapeDecorator>> GetShapesFromFile();
	void UploadToFile(const std::string& filename, std::vector<std::unique_ptr<ShapeDecorator>>& shapes);
private:
	std::ifstream file_;
};