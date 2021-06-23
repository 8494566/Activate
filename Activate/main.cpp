#include "Activate.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Activate w;
    w.show();
    return a.exec();
}
