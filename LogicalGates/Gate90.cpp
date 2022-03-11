#include "Gate90.h"

namespace gate
{

Gate90::Gate90(const QImage& image) : m_image(image)
{
}

Gate90::Gate90(const QPoint& topLeft,
	const double width,
	const double height,
	const QImage& image)
	: m_topLeft(topLeft)
	, m_width(width)
	, m_height(height)
	, m_image(image)
{
}

void Gate90::SetTopLeft(const QPoint& topLeft)
{
	m_topLeft = topLeft;
}

QPoint Gate90::GetTopLeft() const
{
	return m_topLeft;
}

void Gate90::SetWidth(const double width)
{
	m_width = width;
}

double Gate90::GetWidth() const
{
	return m_width;
}

void Gate90::SetHeight(const double height)
{
	m_height = height;
}

double Gate90::GetHeight() const
{
	return m_height;
}

} // namespace gate