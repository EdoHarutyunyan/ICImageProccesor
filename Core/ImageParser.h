#pragma once

#include "IParser.h"

#include <string>
#include <QWidget>
#include "../LogicalGates/Gate.h"
#include "../Helpers/KDTree.h"

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
	void FindNearestGate(const point_t& point);

private:
	std::string m_path;
	std::vector<std::shared_ptr<gate::Gate>> m_detectedGates;
	std::shared_ptr<KDTree> m_kdTree = nullptr;
};

} // namespace parser
