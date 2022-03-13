#include "Gate270.h"

namespace gate
{

Gate270::Gate270(std::string_view imagePath, const InputType inputType) : Gate(inputType)
{
	QImage image;
	image.load(imagePath.data());
	m_image = image.scaled(QSize(250, 500));
}

void Gate270::Initialize(const QPoint& topLeft, const double width, const double height, const size_t id)
{
	Gate::Initialize(topLeft, width, height, id);
}

std::vector<std::pair<double, double>> Gate270::GetConnectionPoints()
{
	if (m_inputType == InputType::One)
	{

	}
	else if (m_inputType == InputType::Two)
	{

	}

	return std::vector<std::pair<double, double>>();
}

void Gate270::SetTopLeft(const QPoint& topLeft)
{
	Gate::SetTopLeft(topLeft);
}

QPoint Gate270::GetTopLeft() const
{
	return Gate::GetTopLeft();
}

void Gate270::SetWidth(const double width)
{
	Gate::SetWidth(width);
}

double Gate270::GetWidth() const
{
	return Gate::GetWidth();
}

void Gate270::SetHeight(const double height)
{
	Gate::SetHeight(height);
}

double Gate270::GetHeight() const
{
	return Gate::GetHeight();
}

void Gate270::SetId(const size_t id)
{
	Gate::SetId(id);
}

size_t Gate270::GetId() const
{
	return Gate::GetId();
}

void Gate270::SetInputType(const InputType inputType)
{
	Gate::SetInputType(inputType);
}

InputType Gate270::GetInputType() const
{
	return Gate::GetInputType();
}

} // namespace gate