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
	const auto gatesToDraw = m_parser->GetGates();
	const auto connectionsToDraw = m_parser->GetAdjacencyMatrix();

	for (const auto gateToDraw : gatesToDraw)
	{
		//QRect rect(gateToDraw->GetTopLeft(), QSize(gateToDraw->GetWidth(), gateToDraw->GetHeight()));
		//QGraphicsRectItem* item = new QGraphicsRectItem(rect);

		QGraphicsPixmapItem* pixmap = new QGraphicsPixmapItem();
		pixmap->setPixmap(QPixmap::fromImage(gateToDraw->GetImage(), Qt::AutoColor));
		pixmap->setFlag(QGraphicsItem::ItemIsMovable);
		pixmap->setPos(gateToDraw->GetTopLeft());

		//pixmap.fromImage(gateToDraw->GetImage(), Qt::AutoColor);
		//QPixmap::fromImage(const QImage & image, Qt::ImageConversionFlags flags = Qt::AutoColor)
		//QBrush brush();

		//item->setBrush(brush);
		//item->setFlag(QGraphicsItem::ItemIsMovable);

		m_scene->addItem(pixmap);
	}

	m_graphicsView->setScene(m_scene);
}

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