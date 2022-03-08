#include "ICImageProccesor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    icimageproccesor::ICImageProccesor icImageProccesor;

    return a.exec();
}
