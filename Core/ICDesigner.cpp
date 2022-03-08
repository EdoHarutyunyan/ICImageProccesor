#include "ICDesigner.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGridLayout>
#include <QGraphicsRectItem>
#include <QPushButton>
#include <QtWidgets/qfiledialog.h>

#include "../Core/ImageParser.h"

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
	QPixmap pixmap;
	pixmap.load("C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\Resources\\And.jpg");
	pixmap.size();

	QRect rect(QPoint(0, 0), QSize(500, 500));


	QImage image(rect.size(), QImage::Format::Format_Mono);
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

void ICDesigner::Display()
{
	// Todo m_scene->clear();
}

void ICDesigner::on_importButton_released()
{
	//QString fileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath());

	// ToDo: file path should be input parameter
	m_parser = new ImageParser("C:\\Users\\eharutyunyan\\Desktop\\Tesis\\ICImageProccesor\\lines.png");

	m_parser->Start();
}
