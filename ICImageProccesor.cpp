#include "ICImageProccesor.h"
#include "Core/ICDesigner.h"

ICImageProccesor::ICImageProccesor(QWidget *parent)
    : QMainWindow(parent)
	, m_icDesigner(new ICDesigner())
{
	m_icDesigner->show();
}
