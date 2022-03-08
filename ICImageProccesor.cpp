#include "ICImageProccesor.h"
#include "Core/ICDesigner.h"

namespace icimageproccesor
{

ICImageProccesor::ICImageProccesor(QWidget *parent)
    : QMainWindow(parent)
	, m_icDesigner(std::make_shared<icdesigner::ICDesigner>())
{
	m_icDesigner->show();
}

} // namespace icimageproccesor