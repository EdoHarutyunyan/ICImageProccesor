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

	QPoint topLeft(center.x() - newWidth / 2, center.y() - newHeight / 2);
	Gate::Initialize(topLeft, newWidth, newHeight, id);
}

std::vector<QPoint> Gate0::GetConnectionPoints()
{
	std::vector<QPoint> points;
	if (m_inputType == InputType::One)
	{
		points.emplace_back(QPoint(m_topLeft.x(), m_topLeft.y() + m_height / 2));
		points.emplace_back(QPoint(m_topLeft.x() + m_width, m_topLeft.y() + m_height / 2));
	}
	else if (m_inputType == InputType::Two)
	{
		points.emplace_back(QPoint(m_topLeft.x(), m_topLeft.y() + m_height / 3));
		points.emplace_back(QPoint(m_topLeft.x(), m_topLeft.y() + 2 * m_height / 3));
		points.emplace_back(QPoint(m_topLeft.x() + m_width, m_topLeft.y() + m_height / 2));
	}

	return points;
}

} // namespace gate