#include "Sport.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sport w;
    w.show();
    return a.exec();
}
