#include "CJanelaMenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JanelaMenu w;
    w.show();
    return a.exec();
}
