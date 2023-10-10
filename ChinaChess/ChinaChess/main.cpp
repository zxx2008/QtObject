#include "ChinaChess.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChinaChess w;
    w.show();
    return a.exec();
}
