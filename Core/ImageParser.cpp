#include "ImageParser.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cassert>

// ToDo: Add Nand, ...


namespace
{
	static constexpr std::string_view andImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\And.jpg" };
	static constexpr std::string_view nandImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Nand.jpg" };
	static constexpr std::string_view orImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Or.jpg" };
	static constexpr std::string_view norImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Nor.jpg" };
	static constexpr std::string_view xorImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Xor.jpg" };
	static constexpr std::string_view xnorImgPath{ "C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\Xnor.jpg" };
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

	QImage andImage;
	andImage.load(andImgPath.data());

	std::map<std::string, GateSharedPtr> gatesMap =
	{
		//const QPoint& top,
		//const QPoint& left,
		//const double width,
		//const double height,
		//const QImage& image)

		{"And", std::make_shared<Gate>(andImage) },
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
		auto gate = gatesMap[tokens[0]];
		//gate->Initialize()

		m_detectedGates.push_back(gate);
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
		QPoint point1(lines[i][0], lines[i][1]);
		QPoint point2(lines[i][2], lines[i][3]);

		FindNearestGates(point1, point2);
		//line(imgSrc, Point(lines[i][0], lines[i][1]),
		//	Point(lines[i][2], lines[i][3]), Scalar(0, 255, 0, 128));
	}
}

void ImageParser::FindNearestGates(const QPoint& point1, const QPoint& point2)
{
	std::vector<std::vector<uint>> matrix;

	for (const auto& detectedGate : m_detectedGates)
	{
		
	}
}

} // namespace parser