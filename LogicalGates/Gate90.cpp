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

} // namespace gate