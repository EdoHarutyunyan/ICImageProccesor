#include "Gate180.h"

namespace gate
{

Gate180::Gate180(const QImage& image) : m_image(image)
{
}

Gate180::Gate180(const QPoint& topLeft,
	const double width,
	const double height,
	const QImage& image)
	: m_topLeft(topLeft)
	, m_width(width)
	, m_height(height)
	, m_image(image)
{
}

void Gate180::SetTopLeft(const QPoint& topLeft)
{
	m_topLeft = topLeft;
}

QPoint Gate180::GetTopLeft() const
{
	return m_topLeft;
}

void Gate180::SetWidth(const double width)
{
	m_width = width;
}

double Gate180::GetWidth() const
{
	return m_width;
}

void Gate180::SetHeight(const double height)
{
	m_height = height;
}

double Gate180::GetHeight() const
{
	return m_height;
}

} // namespace gate