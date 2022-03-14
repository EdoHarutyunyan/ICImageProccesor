#pragma once
#include "Gate.h"

#include <QPoint.h>
#include <QImage.h>

namespace gate
{

class Gate180 : public Gate
{
public:
	Gate180() = default;
	Gate180(std::string_view imagePath, InputType inputType);
	~Gate180() override = default;

	void Initialize(const QPoint& center, double width, double height, size_t id) override;
	std::vector<QPoint> GetConnectionPoints() override;
};

} // namespace gate