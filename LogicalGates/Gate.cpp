#include "Gate.h"


Gate::Gate(const QImage& image) : m_image(image)
{
}

Gate::Gate(const QPoint& top,
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

void Gate::SetTop(const QPoint& top)
{
	m_top = top;
}

QPoint Gate::GetTop() const
{
	return m_top;
}

void Gate::SetLeft(const QPoint& left)
{
	m_left = left;
}

QPoint Gate::GetLeft() const
{
	return m_left;
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
