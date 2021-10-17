#pragma once
#include "IParser.h"
#include <string>
#include <QWidget>

class QPushButton;

class ImageParser : public IParser
{
public:
	ImageParser(const std::string& path);
	void Start() override;

private:
	std::string m_path;
};