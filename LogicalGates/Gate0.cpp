#include "Gate0.h"

namespace
{
	static constexpr double newWidth{ 500 };
	static constexpr double newHeight{ 250 };
}

namespace gate
{

Gate0::Gate0(std::string_view imagePath, const InputType inputType) : Gate(inputType)
{
	QImage image;
	image.load(imagePath.data());
	m_image = image.scaled(QSize(newWidth, newHeight));
}

void Gate0::Initialize(const QPoint& center, const double width, const double height, const size_t id)
{
	Q_UNUSED(width);
	Q_UNUSED(height);

	Gate::Initialize(center, newWidth, newHeight, id);
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

} // namespace gate