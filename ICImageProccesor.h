#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ICImageProccesor.h"
#include "Core/ICDesigner.h"

#include <iostream>

namespace icimageproccesor
{

class ICImageProccesor : public QMainWindow
{
    Q_OBJECT

public:
    ICImageProccesor(QWidget* parent = Q_NULLPTR);

private slots:

private:
    std::shared_ptr<icdesigner::ICDesigner> m_icDesigner{ nullptr };
};

} // namespace icimageproccesor
