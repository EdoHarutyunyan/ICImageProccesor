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
	void on_exportButton_released();
	void on_andButton_released();
	void on_cleanButton_released();

	//void on_addButton_released();
	//void on_nandButton_released();
	//void on_orButton_released();
	//void on_norButton_released();
	//void on_xorButton_released();
	//void on_xnorButton_released();
	//void on_bufferButton_released();
	//void on_notButton_released();
	//void on_wireButton_released();

public:

private:
	void HandleParsedResult();
	void Initialize();
	void SetButton(QPushButton& button, const std::string& iconPath, size_t width, size_t height);
	//void AddGate();

private:
	parser::ParserSharedPtr m_parser{ nullptr };
	std::vector<std::shared_ptr<gate::Gate>> m_gates;
	QGraphicsView* m_graphicsView;
	QGraphicsScene* m_scene;
	QPushButton* m_importButton;
	QPushButton* m_exportButton;
	QPushButton* m_cleanButton;

	QPushButton* m_andButton;
	QPushButton* m_nandButton;
	QPushButton* m_orButton;
	QPushButton* m_norButton;
	QPushButton* m_xorButton;
	QPushButton* m_xnorButton;
	QPushButton* m_bufferButton;
	QPushButton* m_notButton;
	QPushButton* m_wireButton;
};

} // namespace icdesigner

