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

	QPoint topLeft(center.x() - newWidth / 2, center.y() - newHeight / 2);
	Gate::Initialize(topLeft, newWidth, newHeight, id);
}

std::vector<QPoint> Gate270::GetConnectionPoints()
{
	std::vector<QPoint> points;
	if (m_inputType == InputType::One)
	{
		points.emplace_back(QPoint(m_topLeft.x() + m_width / 2, m_topLeft.y()));
		points.emplace_back(QPoint(m_topLeft.x() + m_width / 2, m_topLeft.y() + m_height));
	}
	else if (m_inputType == InputType::Two)
	{
		points.emplace_back(QPoint(m_topLeft.x() + m_width / 3, m_topLeft.y()));
		points.emplace_back(QPoint(m_topLeft.x() + 2 * m_width / 3, m_topLeft.y()));
		points.emplace_back(QPoint(m_topLeft.x() + m_width / 2, m_topLeft.y() + m_height));
	}

	return points;
}

} // namespace gate