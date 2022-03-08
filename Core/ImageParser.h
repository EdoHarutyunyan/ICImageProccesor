#pragma once

#include "IParser.h"

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

private:
	std::string m_path;
};

} // namespace parser
