#pragma once

#include <iostream>

#include <QPoint.h>
#include <QImage.h>

#include "Gate.h"

namespace gate
{

class Gate270 : public Gate
{
public:
	Gate270() = default;
	Gate270(std::string_view imagePath, InputType inputType);
	~Gate270() override = default;

	void Initialize(const QPoint& center, double width, double height, size_t id) override;
	std::vector<QPoint> GetConnectionPoints() override;
};

} // namespace gate