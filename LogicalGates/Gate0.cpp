#include "Gate0.h"

namespace gate
{

Gate0::Gate0(const QImage& image) : m_image(image)
{
}

	Gate0::Gate0(const QPoint& top,
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

void Gate0::SetTop(const QPoint& top)
{
	m_top = top;
}

QPoint Gate0::GetTop() const
{
	return m_top;
}

void Gate0::SetLeft(const QPoint& left)
{
	m_left = left;
}

QPoint Gate0::GetLeft() const
{
	return m_left;
}

void Gate0::SetWidth(const double width)
{
	m_width = width;
}

double Gate0::GetWidth() const
{
	return m_width;
}

void Gate0::SetHeight(const double height)
{
	m_height = height;
}

double Gate0::GetHeight() const
{
	return m_height;
}

} // namespace gate