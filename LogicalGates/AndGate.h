#pragma once

#include "Gate.h"

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