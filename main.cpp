#include "ICImageProccesor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ICImageProccesor w;
    w.show();
    return a.exec();
}
