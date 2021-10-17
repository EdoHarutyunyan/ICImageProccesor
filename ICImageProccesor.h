#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ICImageProccesor.h"

class IParser;
class ICDesigner;
class QPushButton;

class ICImageProccesor : public QMainWindow
{
    Q_OBJECT

public:
    ICImageProccesor(QWidget *parent = Q_NULLPTR);

private slots:
    void on_loadImgButton_released();

private:
    QPushButton* m_laodImgButton;
    ICDesigner* m_icDesigner;
    IParser* m_parser;
};
