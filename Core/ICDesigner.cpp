#include "ICDesigner.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGridLayout>
#include <QGraphicsRectItem>
#include <QPushButton>
#include <QtWidgets/qfiledialog.h>

#include "../Core/ImageParser.h"

namespace icdesigner
{

ICDesigner::ICDesigner(QWidget* parent)
	: QWidget(parent)
	, m_graphicsView(new QGraphicsView(this))
	, m_scene(new QGraphicsScene(this))
	, m_importButton(new QPushButton("Import", this))
	, m_exportButton(new QPushButton("Export", this))
{
	QGridLayout* mainLayout = new QGridLayout();
	mainLayout->addWidget(m_graphicsView, 0, 0, 10, 9);
	mainLayout->addWidget(m_importButton, 0, 10, 1, 1);
	mainLayout->addWidget(m_exportButton, 1, 10, 1, 1);

	// ToDo: add logic gates buttons

	setLayout(mainLayout);
	showMaximized();
	setWindowTitle("IC Image Proccessor");

	Test();

	connect(m_importButton, SIGNAL(released()), this, SLOT(on_importButton_released()));
}

void ICDesigner::Test()
{
	QRect rect(QPoint(0, 0), QSize(128, 72));

	QImage image;
	image.load("C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\And.jpg");
	auto newImg = image.scaled(rect.size());
	//QRect rect(QPoint(0, 0), image.size());
	//QRect rect(QPoint(0, 0), QSize(500, 500));

	QGraphicsRectItem* item = new QGraphicsRectItem(rect);

	QBrush brush(newImg);

	item->setBrush(brush);
	item->setFlag(QGraphicsItem::ItemIsMovable);

	m_scene->addItem(item);
	m_graphicsView->setScene(m_scene);
}

void ICDesigner::HandleParsedResult()
{
	const auto detectedGates = m_parser->GetGates();
	const auto detectedWires = m_parser->GetWires();
	//const auto connectionsToDraw = m_parser->GetAdjacencyMatrix();

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

		m_scene->addItem(pixmap);
	}

	std::shared_ptr<KDTree> kdTree = std::make_shared<KDTree>(gatesPoints);

	for (const auto& wire : detectedWires)
	{
		auto kdPoint1 = kdTree->nearest_point(wire.first);
		auto kdPoint2 = kdTree->nearest_point(wire.second);
		QPoint qPoint1(kdPoint1[0], kdPoint1[1]);
		QPoint qPoint2(kdPoint2[0], kdPoint2[1]);


	}

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

void ICDesigner::Display()
{
	// Todo m_scene->clear();
}

void ICDesigner::on_importButton_released()
{
	//QString fileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath());

	// ToDo: file path should be input parameter
	m_parser = std::make_shared<parser::ImageParser>("C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\test2.jpg");
	m_parser->Start(std::bind([this]()
		{
			HandleParsedResult();
		}));
}

} // namespace icdesigner