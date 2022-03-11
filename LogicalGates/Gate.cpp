#include "Gate.h"

namespace gate
{

Gate::Gate(const QImage& image) : m_image(image)
{
}

Gate::Gate(const QPoint& topLeft,
	const double width,
	const double height,
	const QImage& image)
	: m_topLeft(topLeft)
	, m_width(width)
	, m_height(height)
	, m_image(image)
{
}

void Gate::SetTopLeft(const QPoint& topLeft)
{
	m_topLeft = topLeft;
}

QPoint Gate::GetTopLeft() const
{
	return m_topLeft;
}

void Gate::SetWidth(const double width)
{
	m_width = width;
}

double Gate::GetWidth() const
{
	return m_width;
}

void Gate::SetHeight(const double height)
{
	m_height = height;
}

double Gate::GetHeight() const
{
	return m_height;
}

} // namespace gate