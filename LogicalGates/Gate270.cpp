#include "Gate270.h"

namespace
{
	static constexpr double newWidth{ 250 };
	static constexpr double newHeight{ 500 };
}

namespace gate
{

Gate270::Gate270(std::string_view imagePath, const InputType inputType) : Gate(inputType)
{
	QImage image;
	image.load(imagePath.data());
	m_image = image.scaled(QSize(newWidth, newHeight));
}

void Gate270::Initialize(const QPoint& center, const double width, const double height, const size_t id)
{
	Q_UNUSED(width);
	Q_UNUSED(height);

	Gate::Initialize(center, newWidth, newHeight, id);
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

void Gate270::SetCenter(const QPoint& center)
{
	Gate::SetCenter(center);
}

QPoint Gate270::GetCenter() const
{
	return Gate::GetCenter();
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