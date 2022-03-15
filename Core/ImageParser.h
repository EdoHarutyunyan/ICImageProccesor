#pragma once

#include "IParser.h"
#include "../LogicalGates/Gate.h"
#include "../Helpers/KDTree.h"

#include <opencv2/core/mat.hpp>
#include <string>
#include <QWidget>

class QPushButton;

namespace parser
{

class ImageParser : public IParser
{
public:
	ImageParser(const std::string& path);
	void Start(Callback cb) override;
	std::vector<std::shared_ptr<gate::Gate>> GetGates() const override;
	std::vector<std::pair<point_t, point_t>> GetWires() const override;

private:
	void DetectGates();
	void DetectLines();

private:
	cv::Mat m_image;
	std::vector<std::shared_ptr<gate::Gate>> m_detectedGates;
	std::vector<std::pair<point_t, point_t>> m_wires;
};

} // namespace parser
