#pragma once
#include <iostream>

#include <QPoint.h>
#include <QImage.h>

namespace gate
{

class Gate0
{
public:
	explicit Gate0(const QImage& image);

	Gate0(const QPoint& top, const QPoint& left,
		double width, double height, const QImage& image);

	//void Initialize();
	void SetTop(const QPoint& top);
	QPoint GetTop() const;

	void SetLeft(const QPoint& left);
	QPoint GetLeft() const;

	void SetWidth(double width);
	double GetWidth() const;

	void SetHeight(double height);
	double GetHeight() const;

private:
	QPoint m_top;
	QPoint m_left;
	double m_width{ 0.0 };
	double m_height{ 0.0 };
	QImage m_image;
};

using GateSharedPtr = std::shared_ptr<Gate0>;

} // namespace gate