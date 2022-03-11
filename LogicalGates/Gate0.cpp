#include "Gate0.h"

namespace gate
{

Gate0::Gate0(const QImage& image) : m_image(image)
{
}

Gate0::Gate0(const QPoint& topLeft,
	const double width,
	const double height,
	const QImage& image)
	: m_topLeft(topLeft)
	, m_width(width)
	, m_height(height)
	, m_image(image)
{
}

void Gate0::SetTopLeft(const QPoint& topLeft)
{
	m_topLeft = topLeft;
}

QPoint Gate0::GetTopLeft() const
{
	return m_topLeft;
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