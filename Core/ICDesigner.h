#pragma once
#include <qwidget.h>
#include <vector>

#include "../LogicalGates/Gate.h"
#include "IParser.h"

class QGraphicsView;
class QGraphicsScene;
class QPushButton;

namespace icdesigner
{

class ICDesigner : public QWidget
{
	Q_OBJECT

public:
	explicit ICDesigner(QWidget* parent = nullptr);
	~ICDesigner() = default;

public slots:

private slots:
	void on_importButton_released();

public:
	void Test();
	void Display();

private:
	parser::ParserSharedPtr m_parser{ nullptr };
	std::vector<gate::GateSharedPtr> m_gates;
	QGraphicsView* m_graphicsView;
	QGraphicsScene* m_scene;
	QPushButton* m_importButton;
	QPushButton* m_exportButton;
};

} // namespace icdesigner

