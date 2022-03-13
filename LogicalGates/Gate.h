#pragma once
#include <iostream>

#include <QPoint.h>
#include <QImage.h>

namespace gate
{

enum class InputType : uint8_t
{
	One,
	Two
};

class Gate
{
public:
	Gate() = default;
	Gate(InputType inputType);
	virtual ~Gate() = default;

public:
	void Initialize(const QPoint& topLeft, double width, double height, size_t id);
	virtual std::vector<std::pair<double, double>> GetConnectionPoints();

protected:
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

protected:
	size_t m_id;
	InputType m_inputType{ InputType::Two };
	QPoint m_topLeft;
	double m_width{ 0.0 };
	double m_height{ 0.0 };
	QImage m_image;
};

} // namespace gate