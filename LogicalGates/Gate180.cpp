#include "Gate180.h"

namespace gate
{

Gate180::Gate180(std::string_view imagePath, const InputType inputType) : Gate(inputType)
{
	QImage image;
	image.load(imagePath.data());
	m_image = image.scaled(QSize(500, 250));
}

void Gate180::Initialize(const QPoint& topLeft, const double width, const double height, const size_t id)
{
	Gate::Initialize(topLeft, width, height, id);
}

std::vector<std::pair<double, double>> Gate180::GetConnectionPoints()
{
	if (m_inputType == InputType::One)
	{

	}
	else if (m_inputType == InputType::Two)
	{

	}

	return std::vector<std::pair<double, double>>();
}

void Gate180::SetTopLeft(const QPoint& topLeft)
{
	Gate::SetTopLeft(topLeft);
}

QPoint Gate180::GetTopLeft() const
{
	return Gate::GetTopLeft();
}

void Gate180::SetWidth(const double width)
{
	Gate::SetWidth(width);
}

double Gate180::GetWidth() const
{
	return Gate::GetWidth();
}

void Gate180::SetHeight(const double height)
{
	Gate::SetHeight(height);
}

double Gate180::GetHeight() const
{
	return Gate::GetHeight();
}

void Gate180::SetId(const size_t id)
{
	Gate::SetId(id);
}

size_t Gate180::GetId() const
{
	return Gate::GetId();
}

void Gate180::SetInputType(const InputType inputType)
{
	Gate::SetInputType(inputType);
}

InputType Gate180::GetInputType() const
{
	return Gate::GetInputType();
}

} // namespace gate