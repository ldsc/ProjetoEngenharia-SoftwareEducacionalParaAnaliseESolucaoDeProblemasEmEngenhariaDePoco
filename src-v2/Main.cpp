#include "CJanelaMenu.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QIcon appIcon(":/resources/icons/appicon.png");
    app.setWindowIcon(appIcon);

    JanelaMenu w;
    w.setWindowIcon(appIcon);
    w.setWindowTitle("SEAPEP - Software Educacional de Engenharia de Poço");
    w.show();

    return app.exec();
}
