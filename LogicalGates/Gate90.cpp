#include "Gate90.h"

namespace
{
	static constexpr double newWidth{ 50 };
	static constexpr double newHeight{ 100 };
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

	QPoint topLeft(center.x() - newWidth / 2, center.y() - newHeight / 2);
	Gate::Initialize(topLeft, newWidth, newHeight, id);
}

std::vector<QPoint> Gate90::GetConnectionPoints()
{
	std::vector<QPoint> points;
	if (m_inputType == InputType::One)
	{
		points.emplace_back(QPoint(m_topLeft.x() + m_width / 2, m_topLeft.y()));
		points.emplace_back(QPoint(m_topLeft.x() + m_width / 2, m_topLeft.y() + m_height));
	}
	else if (m_inputType == InputType::Two)
	{
		points.emplace_back(QPoint(m_topLeft.x() + m_width / 3, m_topLeft.y() + m_height));
		points.emplace_back(QPoint(m_topLeft.x() + 2 * m_width / 3, m_topLeft.y() + m_height));
		points.emplace_back(QPoint(m_topLeft.x() + m_width / 2, m_topLeft.y()));
	}

	return points;
}

std::shared_ptr<Gate> Gate90::Clone()
{
	return std::make_shared<Gate90>(*this);
}

} // namespace gate