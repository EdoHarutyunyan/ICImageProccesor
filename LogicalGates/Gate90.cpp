#include "Gate90.h"

namespace
{
	static constexpr double newWidth{ 250 };
	static constexpr double newHeight{ 500 };
}

namespace gate
{

Gate90::Gate90(std::string_view imagePath, const InputType inputType) : Gate(inputType)
{
	QImage image;
	image.load(imagePath.data());
	m_image = image.scaled(QSize(newWidth, newHeight));
}

void Gate90::Initialize(const QPoint& center, const double width, const double height, const size_t id)
{
	Q_UNUSED(width);
	Q_UNUSED(height);

	Gate::Initialize(center, newWidth, newHeight, id);
}

std::vector<std::pair<double, double>> Gate90::GetConnectionPoints()
{
	if (m_inputType == InputType::One)
	{

	}
	else if (m_inputType == InputType::Two)
	{

	}

	return std::vector<std::pair<double, double>>();
}

void Gate90::SetCenter(const QPoint& center)
{
	Gate::SetCenter(center);
}

QPoint Gate90::GetCenter() const
{
	return Gate::GetCenter();
}

void Gate90::SetWidth(const double width)
{
	Gate::SetWidth(width);
}

double Gate90::GetWidth() const
{
	return Gate::GetWidth();
}

void Gate90::SetHeight(const double height)
{
	Gate::SetHeight(height);
}

double Gate90::GetHeight() const
{
	return Gate::GetHeight();
}

void Gate90::SetId(const size_t id)
{
	Gate::SetId(id);
}

size_t Gate90::GetId() const
{
	return Gate::GetId();
}

void Gate90::SetInputType(const InputType inputType)
{
	Gate::SetInputType(inputType);
}

InputType Gate90::GetInputType() const
{
	return Gate::GetInputType();
}

} // namespace gate