#pragma once
#include <iostream>

#include <QPoint.h>
#include <QImage.h>

namespace gate
{

class Gate90
{
public:
	explicit Gate90(const QImage& image);

	Gate90(const QPoint& topLeft, double width, double height, const QImage& image);

	//void Initialize();
	void SetTopLeft(const QPoint& topLeft);
	QPoint GetTopLeft() const;

	void SetWidth(double width);
	double GetWidth() const;

	void SetHeight(double height);
	double GetHeight() const;

private:
	QPoint m_topLeft;
	double m_width{ 0.0 };
	double m_height{ 0.0 };
	QImage m_image;
};

} // namespace gate