#pragma once
#include "Gate.h"

#include <QPoint.h>
#include <QImage.h>

namespace gate
{

class Gate0 : public Gate
{
public:
	Gate0() = default;
	Gate0(std::string_view imagePath, InputType inputType);
	~Gate0() override = default;

	void Initialize(const QPoint & center, double width, double height, size_t id);
	std::vector<std::pair<double, double>> GetConnectionPoints() override;
	
	void SetCenter(const QPoint& center);
	QPoint GetCenter() const;

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