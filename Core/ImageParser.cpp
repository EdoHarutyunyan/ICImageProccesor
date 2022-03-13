#include "ImageParser.h"
#include "../Helpers/KDTree.h"
#include "../LogicalGates/Gate0.h"
#include "../LogicalGates/Gate90.h"
#include "../LogicalGates/Gate180.h"
#include "../LogicalGates/Gate270.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <cassert>

namespace
{
	static constexpr std::string_view and0ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\And0.jpg" };
	static constexpr std::string_view nand0ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Nand0.jpg" };
	static constexpr std::string_view or0ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Or0.jpg" };
	static constexpr std::string_view nor0ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Nor0.jpg" };
	static constexpr std::string_view xor0ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Xor0.jpg" };
	static constexpr std::string_view xnor0ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Xnor0.jpg" };
	static constexpr std::string_view not0ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Not0.jpg" };
	static constexpr std::string_view buffer0ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Buffer0.jpg" };

	static constexpr std::string_view and90ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\And90.jpg" };
	static constexpr std::string_view nand90ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Nand90.jpg" };
	static constexpr std::string_view or90ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Or90.jpg" };
	static constexpr std::string_view nor90ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Nor90.jpg" };
	static constexpr std::string_view xor90ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Xor90.jpg" };
	static constexpr std::string_view xnor90ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Xnor90.jpg" };
	static constexpr std::string_view not90ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Not90.jpg" };
	static constexpr std::string_view buffer90ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Buffer90.jpg" };

	static constexpr std::string_view and180ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\And180.jpg" };
	static constexpr std::string_view nand180ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Nand180.jpg" };
	static constexpr std::string_view or180ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Or180.jpg" };
	static constexpr std::string_view nor180ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Nor180.jpg" };
	static constexpr std::string_view xor180ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Xor180.jpg" };
	static constexpr std::string_view xnor180ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Xnor180.jpg" };
	static constexpr std::string_view not180ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Not180.jpg" };
	static constexpr std::string_view buffer180ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Buffer180.jpg" };

	static constexpr std::string_view and270ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\And270.jpg" };
	static constexpr std::string_view nand270ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Nand270.jpg" };
	static constexpr std::string_view or270ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Or270.jpg" };
	static constexpr std::string_view nor270ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Nor270.jpg" };
	static constexpr std::string_view xor270ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Xor270.jpg" };
	static constexpr std::string_view xnor270ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Xnor270.jpg" };
	static constexpr std::string_view not270ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Not270.jpg" };
	static constexpr std::string_view buffer270ImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Buffer270.jpg" };
} // namespace

namespace parser
{

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
	using namespace gate;

	// Open file
	// Read lines into vector
	std::vector<std::string> fileLines;

	std::map<std::string, std::shared_ptr<Gate>> gatesMap =
	{
		{"And0", std::make_shared<Gate0>(and0ImgPath, InputType::Two) },
		{"Nand0", std::make_shared<Gate0>(nand0ImgPath, InputType::Two) },
		{"Or0", std::make_shared<Gate0>(or0ImgPath, InputType::Two) },
		{"Nor0", std::make_shared<Gate0>(nor0ImgPath, InputType::Two) },
		{"Xor0", std::make_shared<Gate0>(xor0ImgPath, InputType::Two) },
		{"Xnor0", std::make_shared<Gate0>(xnor0ImgPath, InputType::Two) },
		{"Not0", std::make_shared<Gate0>(not90ImgPath, InputType::One) },
		{"Buffer0", std::make_shared<Gate0>(buffer90ImgPath, InputType::One) },

		{"And90", std::make_shared<Gate90>(and90ImgPath, InputType::Two) },
		{"Nand90", std::make_shared<Gate90>(nand90ImgPath, InputType::Two) },
		{"Or90", std::make_shared<Gate90>(or90ImgPath, InputType::Two) },
		{"Nor90", std::make_shared<Gate90>(nor90ImgPath, InputType::Two) },
		{"Xor90", std::make_shared<Gate90>(xor90ImgPath, InputType::Two) },
		{"Xnor90", std::make_shared<Gate90>(xnor90ImgPath, InputType::Two) },
		{"Not90", std::make_shared<Gate90>(not90ImgPath, InputType::One) },
		{"Buffer90", std::make_shared<Gate90>(buffer90ImgPath, InputType::One) },

		{"And180", std::make_shared<Gate180>(and180ImgPath, InputType::Two) },
		{"Nand180", std::make_shared<Gate180>(nand180ImgPath, InputType::Two) },
		{"Or180", std::make_shared<Gate180>(or180ImgPath, InputType::Two) },
		{"Nor180", std::make_shared<Gate180>(nor180ImgPath, InputType::Two) },
		{"Xor180", std::make_shared<Gate180>(xor180ImgPath, InputType::Two) },
		{"Xnor180", std::make_shared<Gate180>(xnor180ImgPath, InputType::Two) },
		{"Not180", std::make_shared<Gate180>(not180ImgPath, InputType::One) },
		{"Buffer180", std::make_shared<Gate180>(buffer180ImgPath, InputType::One) },

		{"And270", std::make_shared<Gate270>(and270ImgPath, InputType::Two) },
		{"Nand270", std::make_shared<Gate270>(nand270ImgPath, InputType::Two) },
		{"Or270", std::make_shared<Gate270>(or270ImgPath, InputType::Two) },
		{"Nor270", std::make_shared<Gate270>(nor270ImgPath, InputType::Two) },
		{"Xor270", std::make_shared<Gate270>(xor270ImgPath, InputType::Two) },
		{"Xnor270", std::make_shared<Gate270>(xnor270ImgPath, InputType::Two) },
		{"Not270", std::make_shared<Gate270>(not270ImgPath, InputType::One) },
		{"Buffer270", std::make_shared<Gate270>(buffer270ImgPath, InputType::One) },
	};

	size_t id{ 0u };
	for (const auto& line : fileLines)
	{
		std::vector<std::string> tokens;
		split(line, tokens);
		std::shared_ptr<Gate> gate = gatesMap[tokens[0]];

		// to do int-double
		const QPoint topLeft(std::stoi(tokens[1]), std::stoi(tokens[2]));

		gate->Initialize(topLeft, std::stod(tokens[3]), std::stod(tokens[4]), id++);

		m_detectedGates.push_back(gate);
	}

	CreateKDTree();
}

void ImageParser::CreateKDTree()
{
	pointVec gatesPoints;

	for (const auto& gate : m_detectedGates)
	{
		const auto connectionPoints = gate->GetConnectionPoints();
		for (const auto& point : connectionPoints)
		{
			gatesPoints.push_back({ point.first, point.second });
		}
	}

	m_kdTree = std::make_shared<KDTree>(gatesPoints);
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
		FindNearestGate({ lines[i][0], lines[i][1] });
		FindNearestGate({ lines[i][2], lines[i][3] });

		//QPoint point1(lines[i][0], lines[i][1]);
		//QPoint point2(lines[i][2], lines[i][3]);

		//FindNearestGate(point1, point2);
		//line(imgSrc, Point(lines[i][0], lines[i][1]),
		//	Point(lines[i][2], lines[i][3]), Scalar(0, 255, 0, 128));
	}
}

// add second point
void ImageParser::FindNearestGate(const point_t& point)
{
	m_kdTree->nearest_point(point);

	std::vector<std::vector<uint>> matrix;

	for (const auto& detectedGate : m_detectedGates)
	{
		
	}
}

} // namespace parser