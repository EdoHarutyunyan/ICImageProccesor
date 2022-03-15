#include "ImageParser.h"
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
{
	m_image = cv::imread(path, cv::IMREAD_COLOR);
	if (m_image.empty())
	{
		std::cerr << "Error while opening file.";
		assert(false);
	}
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

void ImageParser::Start(Callback cb)
{
	DetectGates();
	DetectLines();

	cb();
}

void ImageParser::DetectGates()
{
	using namespace gate;

	// Open file
	// Read lines into vector
	std::vector<std::string> fileLines = {
		"Nand0 50 25 200 100",
		"Xor0 250 225 200 100",
		"And0 450 425 200 100",
		"Xor0 650 625 200 100",
		"Nand0 850 825 200 100",
	};

	std::map<std::string, std::shared_ptr<Gate>> gatesMap =
	{
		{"And0", std::make_shared<Gate0>(and0ImgPath, InputType::Two) },
		{"Nand0", std::make_shared<Gate0>(nand0ImgPath, InputType::Two) },
		{"Or0", std::make_shared<Gate0>(or0ImgPath, InputType::Two) },
		{"Nor0", std::make_shared<Gate0>(nor0ImgPath, InputType::Two) },
		{"Xor0", std::make_shared<Gate0>(xor0ImgPath, InputType::Two) },
		{"Xnor0", std::make_shared<Gate0>(xnor0ImgPath, InputType::Two) },
		{"Not0", std::make_shared<Gate0>(not0ImgPath, InputType::One) },
		{"Buffer0", std::make_shared<Gate0>(buffer0ImgPath, InputType::One) },

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
		std::shared_ptr<Gate> gate = gatesMap.at(tokens[0])->Clone();

		// to do int-double
		const QPoint center(std::stoi(tokens[1]), std::stoi(tokens[2]));
		gate->Initialize(center, std::stod(tokens[3]), std::stod(tokens[4]), id++);

		m_detectedGates.push_back(gate);

		// Draw filled rect with line thickness 1 and white color on source image
		cv::Rect rect = cv::Rect(gate->GetTopLeft().x(), gate->GetTopLeft().y(), gate->GetWidth(), gate->GetHeight());
		cv::rectangle(m_image, rect, cv::Scalar(255, 255, 255), cv::FILLED, 1, 0);
	}
}

void ImageParser::DetectLines()
{
	using namespace cv;

	Mat imgGray;
	Mat imgBlur;
	Mat imgCanny;

	cvtColor(m_image, imgGray, COLOR_BGR2GRAY);
	threshold(imgGray, imgGray, 100, 255, THRESH_BINARY);
	imgGray = ~imgGray;
	cv::Canny(imgGray, imgCanny, 75, 200);
	std::vector<Vec4i> linesP;

	HoughLinesP(imgCanny, linesP, 1, CV_PI / 180, 10, 10, 25); // runs the actual detection

	std::vector<std::pair<cv::Point, cv::Point>> allLines;
	for (int i = 0; i < linesP.size(); i++)
	{
		Vec4i l = linesP[i];
		allLines.push_back({ Point(l[0], l[1]), Point(l[2], l[3]) });
	}

	std::vector<std::vector<std::pair<cv::Point, cv::Point>>> wires;
	while (!allLines.empty())
	{
		std::vector<std::pair<cv::Point, cv::Point>> current{ allLines[0] };
		allLines.erase(allLines.begin());
		for (int i = 0; i < allLines.size(); ++i)
		{
			auto fl = current[0];
			auto ll = current.back();
			auto l = allLines[i];
			const int thresh = 35;
			bool isNearPoint = false;
			std::pair<cv::Point, cv::Point> found;
			auto insert_point = allLines.begin();

			// Todo: code duplication
			if (norm(fl.first - l.first) < thresh)
			{
				isNearPoint = true;
				found = { l.second, l.first };
				insert_point = current.begin();
			}
			else if (norm(fl.first - l.second) < thresh)
			{
				isNearPoint = true;
				found = { l.first, l.second };
				insert_point = current.begin();
			}
			else if (norm(ll.second - l.second) < thresh)
			{
				isNearPoint = true;
				found = { l.second, l.first };
				insert_point = current.end();
			}
			else if (norm(ll.second - l.first) < thresh)
			{
				isNearPoint = true;
				found = { l.first, l.second };
				insert_point = current.end();
			}

			if (isNearPoint)
			{
				allLines.erase(allLines.begin() + i);
				--i;

				bool matched = false;
				for (auto l1 : current)
				{
					if ((norm(l1.first - found.first) < thresh && norm(l1.second - found.second) < thresh)
						|| (norm(l1.second - found.first) < thresh && norm(l1.first - found.second) < thresh))
					{
						matched = true;
					}
				}

				if (!matched)
				{
					current.insert(insert_point, found);
				}
			}
		}

		wires.push_back(current);
	}

	for (auto& wire : wires)
	{
		m_wires.emplace_back(point_t(wire[0].first.x, wire[0].first.y),
			point_t(wire.back().second.x, wire.back().second.y));
	}
}

std::vector<std::shared_ptr<gate::Gate>> ImageParser::GetGates() const
{
	return m_detectedGates;
}

std::vector<std::pair<point_t, point_t>> ImageParser::GetWires() const
{
	return m_wires;
}

} // namespace parser