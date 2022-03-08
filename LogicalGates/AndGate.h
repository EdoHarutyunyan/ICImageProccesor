#pragma once

#include "Gate.h"

namespace gate
{

class AndGate : public Gate
{
public:
	AndGate(const QPoint& top,
		const QPoint& left,
		const double width,
		const double height,
		const QImage& image)
		: Gate(top, left, width, height, image)
	{
	}
};

} // namespace gate