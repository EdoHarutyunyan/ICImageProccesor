#pragma once
#include <qwidget.h>
#include <vector>

#include "../LogicalGates/Gate.h"

class QGraphicsView;
class QGraphicsScene;
class QPushButton;
class IParser;

class ICDesigner : public QWidget
{
	Q_OBJECT

public:
	explicit ICDesigner(QWidget* parent = nullptr);
	~ICDesigner() = default;
private:

public slots:

private slots:
	void on_importButton_released();

public:
	void Test();
	void Display();

private:
	IParser* m_parser;
	QGraphicsView* m_graphicsView;
	QGraphicsScene* m_scene;
	QPushButton* m_importButton;
	QPushButton* m_exportButton;
	std::vector<Gate*> m_gates;
};

