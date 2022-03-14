#pragma once
#include "Gate.h"

#include <QPoint.h>
#include <QImage.h>

namespace gate
{

class Gate90 : public Gate
{
public:
	Gate90() = default;
	Gate90(std::string_view imagePath, InputType inputType);
	~Gate90() override = default;

	void Initialize(const QPoint& center, double width, double height, size_t id) override;
	std::vector<QPoint> GetConnectionPoints() override;
};

} // namespace gate