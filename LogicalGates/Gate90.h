#pragma once
#include "Gate.h"

#include <QPoint.h>
#include <QImage.h>

namespace gate
{

class Gate90 : public Gate
{
public:
	Gate90() = default;
	Gate90(std::string_view imagePath, InputType inputType);
	~Gate90() override = default;

	void Initialize(const QPoint & topLeft, double width, double height, size_t id);
	std::vector<std::pair<double, double>> GetConnectionPoints() override;

	void SetTopLeft(const QPoint& topLeft);
	QPoint GetTopLeft() const;

	void SetWidth(double width);
	double GetWidth() const;

	void SetHeight(double height);
	double GetHeight() const;

	void SetId(size_t id);
	size_t GetId() const;

	void SetInputType(InputType inputType);
	InputType GetInputType() const;
};

} // namespace gate