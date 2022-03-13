#include "Gate.h"

namespace gate
{

Gate::Gate(const InputType inputType)
	: m_inputType(inputType)
{
}

void Gate::Initialize(const QPoint& center,
	const double width,
	const double height,
	const size_t id)
{
	SetCenter(center);
	SetWidth(width);
	SetHeight(height);
	SetId(id);
}

std::vector<std::pair<double, double>> Gate::GetConnectionPoints()
{
	assert(false);
	return std::vector<std::pair<double, double>>();
}

void Gate::SetCenter(const QPoint& center)
{
	m_center = center;
}

QPoint Gate::GetCenter() const
{
	return m_center;
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

void Gate::SetId(const size_t id)
{
	m_id = id;
}

size_t Gate::GetId() const
{
	return m_id;
}

void Gate::SetInputType(const InputType inputType)
{
	m_inputType = inputType;
}

InputType Gate::GetInputType() const
{
	return m_inputType;
}

} // namespace gate