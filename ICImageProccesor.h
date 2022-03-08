#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ICImageProccesor.h"

class ICDesigner;

class ICImageProccesor : public QMainWindow
{
    Q_OBJECT

public:
    ICImageProccesor(QWidget *parent = Q_NULLPTR);

private slots:

private:
    ICDesigner* m_icDesigner;
};
