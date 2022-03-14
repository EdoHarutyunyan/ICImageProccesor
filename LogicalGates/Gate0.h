#pragma once
#include "Gate.h"

#include <QPoint.h>
#include <QImage.h>

namespace gate
{

class Gate0 : public Gate
{
public:
	Gate0() = default;
	Gate0(std::string_view imagePath, InputType inputType);
	~Gate0() override = default;

	void Initialize(const QPoint& center, double width, double height, size_t id) override;
	std::vector<QPoint> GetConnectionPoints() override;
};

} // namespace gate