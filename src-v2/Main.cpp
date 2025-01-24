#include "CSimuladorPoco.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CSimuladorPoco w;
    w.show();
    return a.exec();
}
