#include "Gate0.h"

namespace gate
{

Gate0::Gate0(std::string_view imagePath, const InputType inputType) : Gate(inputType)
{
	QImage image;
	image.load(imagePath.data());
	m_image = image.scaled(QSize(500, 250));
}

void Gate0::Initialize(const QPoint& topLeft, const double width, const double height, const size_t id)
{
	Gate::Initialize(topLeft, width, height, id);
}

std::vector<std::pair<double, double>> Gate0::GetConnectionPoints()
{
	if (m_inputType == InputType::One)
	{

	}
	else if (m_inputType == InputType::Two)
	{

	}

	return std::vector<std::pair<double, double>>();
}

void Gate0::SetTopLeft(const QPoint& topLeft)
{
	Gate::SetTopLeft(topLeft);
}

QPoint Gate0::GetTopLeft() const
{
	return Gate::GetTopLeft();
}

void Gate0::SetWidth(const double width)
{
	Gate::SetWidth(width);
}

double Gate0::GetWidth() const
{
	return Gate::GetWidth();
}

void Gate0::SetHeight(const double height)
{
	Gate::SetHeight(height);
}

double Gate0::GetHeight() const
{
	return Gate::GetHeight();
}

void Gate0::SetId(const size_t id)
{
	Gate::SetId(id);
}

size_t Gate0::GetId() const
{
	return Gate::GetId();
}

void Gate0::SetInputType(const InputType inputType)
{
	Gate::SetInputType(inputType);
}

InputType Gate0::GetInputType() const
{
	return Gate::GetInputType();
}

} // namespace gate