#include "Gate270.h"

namespace gate
{

Gate270::Gate270(const QImage& image) : m_image(image)
{
}

Gate270::Gate270(const QPoint& top,
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

void Gate270::SetTop(const QPoint& top)
{
	m_top = top;
}

QPoint Gate270::GetTop() const
{
	return m_top;
}

void Gate270::SetLeft(const QPoint& left)
{
	m_left = left;
}

QPoint Gate270::GetLeft() const
{
	return m_left;
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