#include "ImageParser.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cassert>

// ToDo: Add Nand, ...
#include "../LogicalGates/AndGate.h"
#include "../LogicalGates/NorGate.h"
#include "../LogicalGates/OrGate.h"
#include "../LogicalGates/XorGate.h"

ImageParser::ImageParser(const std::string& path)
	: m_path(path)
{
}

void split(const std::string& line, std::vector<std::string>& res)
{
	std::stringstream ss(line);
	std::string item;

	while (std::getline(ss, item, ' '))
	{
		if (item.length() > 0)
		{
			res.push_back(item);
		}
	}
}

void ImageParser::Start()
{
	DetectGates();
	DetectLines();
}

void ImageParser::DetectGates()
{
	// Open file
	// Read lines into vector
	std::vector<std::string> fileLines;

	std::map<std::string, Gate*> gatesMap =
	{
		//const QPoint& top,
		//const QPoint& left,
		//const double width,
		//const double height,
		//const QImage& image)

		//{"And", new AndGate() },
		//{"Nand", new AndGate() },
		//{"Or", new AndGate() },
		//{"Nor", new AndGate() },
		//{"Xor", new AndGate() },
		//{"Xnor", new AndGate() },
		//{"Buffer", new AndGate() },
		//{"Not", new AndGate() },
	};

	for (const auto& line : fileLines)
	{
		std::vector<std::string> tokens;
		split(line, tokens);
		//gatesMap[tokens[0]]
		//switch (switch_on)
		//{
		//default:
		//	break;
		//}
	}
}

void ImageParser::DetectLines()
{
	using namespace cv;

	Mat imgSrc = imread(m_path, IMREAD_COLOR);
	if (imgSrc.empty())
	{
		std::cerr << "Error while opening file.";
		assert(false);
		return;
	}

	Mat imgGray;
	Mat imgBlur;
	Mat imgCanny;

	cvtColor(imgSrc, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	
	// Detect lines
	std::vector<Vec4f> lines;
	HoughLinesP(imgCanny, lines, 1, CV_PI / 180, 80, 30, 10);
	for (size_t i = 0; i < lines.size(); i++)
	{
		line(imgSrc, Point(lines[i][0], lines[i][1]),
			Point(lines[i][2], lines[i][3]), Scalar(0, 255, 0, 128));
	}
}


