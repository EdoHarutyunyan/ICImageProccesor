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
	void Start() override;

private:
	void DetectGates();
	void DetectLines();
	void CreateKDTree();
	size_t FindNearestGate(const point_t& point);

private:
	cv::Mat m_image;
	std::vector<std::shared_ptr<gate::Gate>> m_detectedGates;
	std::shared_ptr<KDTree> m_kdTree = nullptr;
};

} // namespace parser
