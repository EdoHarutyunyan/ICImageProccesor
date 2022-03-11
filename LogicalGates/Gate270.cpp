#include "Gate270.h"

namespace gate
{

Gate270::Gate270(const QImage& image) : m_image(image)
{
}

Gate270::Gate270(const QPoint& topLeft,
	const double width,
	const double height,
	const QImage& image)
	: m_topLeft(topLeft)
	, m_width(width)
	, m_height(height)
	, m_image(image)
{
}

void Gate270::SetTopLeft(const QPoint& topLeft)
{
	m_topLeft = topLeft;
}

QPoint Gate270::GetTopLeft() const
{
	return m_topLeft;
}

void Gate270::SetWidth(const double width)
{
	m_width = width;
}

double Gate270::GetWidth() const
{
	return m_width;
}

void Gate270::SetHeight(const double height)
{
	m_height = height;
}

double Gate270::GetHeight() const
{
	return m_height;
}

} // namespace gate