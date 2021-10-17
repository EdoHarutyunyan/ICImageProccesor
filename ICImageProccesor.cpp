#include "ICImageProccesor.h"
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qstring.h>
#include <qfiledialog.h>

#include "Core/ImageParser.h"
#include "Core/ICDesigner.h"

ICImageProccesor::ICImageProccesor(QWidget *parent)
    : QMainWindow(parent)
    , m_laodImgButton(new QPushButton(this))
{
    connect(m_laodImgButton, SIGNAL(released()), this, SLOT(on_loadImgButton_released()));
}

void ICImageProccesor::on_loadImgButton_released()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));

    m_icDesigner = new ICDesigner();

    // ToDo: file path should be input parameter
    m_parser = new ImageParser(fileName.toStdString());
    this->hide();

    m_parser->Start();
    m_icDesigner->show();
}
