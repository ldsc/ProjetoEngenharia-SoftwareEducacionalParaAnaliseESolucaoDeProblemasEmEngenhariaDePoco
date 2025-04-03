#include "CJanelaMenu.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile styleFile(":/resources/styles/lightstyle.qss");
    styleFile.open(QFile::ReadOnly);
    QString style(styleFile.readAll());
    qApp->setStyleSheet(style);

    QIcon appIcon(":/resources/icons/appicon.png");
    app.setWindowIcon(appIcon);

    JanelaMenu w;
    w.setWindowIcon(appIcon);
    w.setWindowTitle("SEAPEP - Software Educacional de Engenharia de Poço");
    w.show();

    return app.exec();
}
