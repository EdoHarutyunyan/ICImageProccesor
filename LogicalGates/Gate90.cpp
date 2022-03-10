#include "Gate90.h"

namespace gate
{

Gate90::Gate90(const QImage& image) : m_image(image)
{
}

Gate90::Gate90(const QPoint& top,
	const QPoint& left,
	const double width,
	const double height,
	const QImage& image)
	: m_top(top)
	, m_left(left)
	, m_width(width)
	, m_height(height)
	, m_image(image)
{
}

void Gate90::SetTop(const QPoint& top)
{
	m_top = top;
}

QPoint Gate90::GetTop() const
{
	return m_top;
}

void Gate90::SetLeft(const QPoint& left)
{
	m_left = left;
}

QPoint Gate90::GetLeft() const
{
	return m_left;
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