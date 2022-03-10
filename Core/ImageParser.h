#pragma once

#include "IParser.h"

#include <string>
#include <QWidget>
#include "../LogicalGates/Gate.h"

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
	void FindNearestGates(const QPoint& point1, const QPoint& point2);

private:
	std::string m_path;
	std::vector<gate::GateSharedPtr> m_detectedGates;
};

} // namespace parser
