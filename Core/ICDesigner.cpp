#include "ICDesigner.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGridLayout>
#include <QGraphicsRectItem>
#include <QPushButton>
#include <QtWidgets/qfiledialog.h>
#include <QBuffer>
#include <QSaveFile>
#include <QLabel>

#include "../Core/ImageParser.h"

namespace icdesigner
{

ICDesigner::ICDesigner(QWidget* parent)
	: QWidget(parent)
	, m_graphicsView(new QGraphicsView(this))
	, m_scene(new QGraphicsScene(this))
	, m_importButton(new QPushButton("Import", this))
	, m_exportButton(new QPushButton("Export", this))
	, m_cleanButton(new QPushButton("Clean", this))
	, m_andButton(new QPushButton())
	, m_nandButton(new QPushButton())
	, m_orButton(new QPushButton())
	, m_norButton(new QPushButton())
	, m_xorButton(new QPushButton())
	, m_xnorButton(new QPushButton())
	, m_bufferButton(new QPushButton())
	, m_notButton(new QPushButton())
	, m_wireButton(new QPushButton())
{
	Initialize();
	showMaximized();
	setWindowTitle("IC Image Proccessor");

	connect(m_importButton, SIGNAL(released()), this, SLOT(on_importButton_released()));
	connect(m_exportButton, SIGNAL(released()), this, SLOT(on_exportButton_released()));
	connect(m_andButton, SIGNAL(released()), this, SLOT(on_andButton_released()));
}

void ICDesigner::on_exportButton_released()
{
	QString directory = QFileDialog::getExistingDirectory(this, "Choose the directory to export the image", QDir::homePath());

	if (directory == "")
	{
		return;
	}
	QPixmap screen = QWidget::grab(QRect(QPoint(0,0), QSize(500, 500)));

	screen.save("saved.png");
}

void ICDesigner::on_andButton_released()
{
}

void ICDesigner::on_cleanButton_released()
{
}

void ICDesigner::HandleParsedResult()
{
	m_scene->clear();

	const auto detectedGates = m_parser->GetGates();
	const auto detectedWires = m_parser->GetWires();

	pointVec gatesPoints;
	for (const auto detectedGate : detectedGates)
	{
		const auto id = detectedGate->GetId();
		const auto connectionPoints = detectedGate->GetConnectionPoints();
		for (const auto& point : connectionPoints)
		{
			gatesPoints.emplace_back(std::make_pair(id, point_t((double)point.x(), (double)point.y())));
		}

		QGraphicsPixmapItem* pixmap = new QGraphicsPixmapItem();
		pixmap->setPixmap(QPixmap::fromImage(detectedGate->GetImage(), Qt::AutoColor));
		pixmap->setFlag(QGraphicsItem::ItemIsMovable);
		pixmap->setPos(detectedGate->GetTopLeft());
		
		//QGraphicsRectItem* rectitem = new QGraphicsRectItem(pixmap->boundingRect());
		//rectitem->setPos(detectedGate->GetTopLeft());

		m_scene->addItem(pixmap);
		//m_scene->addItem(rectitem);
	}

	for (const auto& detectedWire : detectedWires)
	{
		QLine qline(QPoint(detectedWire.first[0], detectedWire.first[1]), QPoint(detectedWire.second[0], detectedWire.second[1]));
		QGraphicsLineItem* line = new QGraphicsLineItem(qline);
		m_scene->addItem(line);
	}

	//std::shared_ptr<KDTree> kdTree = std::make_shared<KDTree>(gatesPoints);

	//for (const auto& wire : detectedWires)
	//{
	//	auto kdPoint1 = kdTree->nearest_point(wire.first);
	//	auto kdPoint2 = kdTree->nearest_point(wire.second);
	//	QPoint qPoint1(kdPoint1[0], kdPoint1[1]);
	//	QPoint qPoint2(kdPoint2[0], kdPoint2[1]);


	//}

	m_graphicsView->setScene(m_scene);
}

//size_t ImageParser::FindNearestGate(const point_t& point)
//{
//	auto kdPoint = m_kdTree->nearest_point(point);
//	QPoint qPoint(kdPoint[0], kdPoint[1]);
//
//	for (const auto& gate : m_detectedGates)
//	{
//		const auto connectionPoints = gate->GetConnectionPoints();
//		for (const auto& point : connectionPoints)
//		{
//			if (qPoint == point)
//			{
//				return gate->GetId();
//			}
//		}
//	}
//
//	assert(false);
//	return 0u;
//}

void ICDesigner::Initialize()
{
	QGridLayout* mainLayout = new QGridLayout();
	mainLayout->addWidget(m_graphicsView, 0, 0, 15, 9);
	mainLayout->addWidget(m_importButton, 0, 10, 1, 1);
	mainLayout->addWidget(m_exportButton, 1, 10, 1, 1);
	mainLayout->addWidget(m_cleanButton, 2, 10, 1, 1);

	QFrame* line = new QFrame();
	line->setGeometry(QRect(/* ... */));
	line->setFrameShape(QFrame::HLine); // Replace by VLine for vertical line
	line->setFrameShadow(QFrame::Sunken);
	mainLayout->addWidget(line, 3, 10, 1, 1);

	// ToDo: add group names
	//QLabel* gatesLabel = new QLabel("Gates", this);

	//mainLayout->addWidget(gatesLabel, 2, 10, 1, 1, Qt::AlignCenter);

	SetButton(*m_andButton, "./Icons/Icon_And.jpg", 102, 53);
	SetButton(*m_nandButton, "./Icons/Icon_Nand.jpg", 102, 53);
	SetButton(*m_orButton, "./Icons/Icon_Or.jpg", 102, 53);
	SetButton(*m_norButton, "./Icons/Icon_Nor.jpg", 102, 53);
	SetButton(*m_xorButton, "./Icons/Icon_Xor.jpg", 102, 53);
	SetButton(*m_xnorButton, "./Icons/Icon_Xnor.jpg", 102, 53);
	SetButton(*m_bufferButton, "./Icons/Icon_Buffer.jpg", 102, 60);
	SetButton(*m_notButton, "./Icons/Icon_Not.jpg", 102, 65);

	mainLayout->addWidget(m_andButton, 5, 10, 1, 1);
	mainLayout->addWidget(m_nandButton, 6, 10, 1, 1);
	mainLayout->addWidget(m_orButton, 7, 10, 1, 1);
	mainLayout->addWidget(m_norButton, 8, 10, 1, 1);
	mainLayout->addWidget(m_xorButton, 9, 10, 1, 1);
	mainLayout->addWidget(m_xnorButton, 10, 10, 1, 1);
	mainLayout->addWidget(m_bufferButton, 11, 10, 1, 1);
	mainLayout->addWidget(m_notButton, 12, 10, 1, 1);

	QFrame* line2 = new QFrame();
	line2->setGeometry(QRect(/* ... */));
	line2->setFrameShape(QFrame::HLine); // Replace by VLine for vertical line
	line2->setFrameShadow(QFrame::Sunken);
	mainLayout->addWidget(line2, 13, 10, 1, 1);

	SetButton(*m_wireButton, "./Icons/Icon_Line.png", 102, 102);
	mainLayout->addWidget(m_wireButton, 14, 10, 1, 1);

	setLayout(mainLayout);
}

void ICDesigner::SetButton(QPushButton& button, const std::string& iconPath, const size_t width, const size_t height)
{
	button.setFixedWidth(width);
	button.setFixedHeight(height);

	QPixmap andPixmap(iconPath.c_str());
	QIcon andIcon(andPixmap);
	button.setIcon(andIcon);
	button.setIconSize(andPixmap.rect().size());
}

void ICDesigner::on_importButton_released()
{
	//QString fileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath());

	// ToDo: file path should be input parameter
	m_parser = std::make_shared<parser::ImageParser>("./test_1.jpg");
	m_parser->Start(std::bind([this]()
		{
			HandleParsedResult();
		}));
}

} // namespace icdesigner