QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CFluido.cpp \
    CGnuplot.cpp \
    CJanelaAdicionarFluido.cpp \
    CJanelaAdicionarTrechoTubulacao.cpp \
    CJanelaGraficoPressaoHidroestatica.cpp \
    CJanelaMenu.cpp \
    CModeloBingham.cpp \
    CModeloNewtoniano.cpp \
    CModeloPotencia.cpp \
    CModeloReologico.cpp \
    CObjetoPoco.cpp \
    CRelatorioSimulacao.cpp \
    CSimuladorPerdaTubulacao.cpp \
    CSimuladorReologico.cpp \
    CTrechoTubulacao.cpp \
    Main.cpp \
    qcustomplot.cpp

HEADERS += \
    CFluido.h \
    CGnuplot.h \
    CJanelaAdicionarFluido.h \
    CJanelaAdicionarTrechoTubulacao.h \
    CJanelaGraficoPressaoHidroestatica.h \
    CJanelaMenu.h \
    CModeloBingham.h \
    CModeloNewtoniano.h \
    CModeloPotencia.h \
    CModeloReologico.h \
    CObjetoPoco.h \
    CRelatorioSimulacao.h \
    CSimuladorPerdaTubulacao.h \
    CSimuladorReologico.h \
    CTrechoTubulacao.h \
    qcustomplot.h

FORMS += \
    CJanelaAdicionarFluido.ui \
    CJanelaAdicionarTrechoTubulacao.ui \
    CJanelaGraficoPressaoHidroestatica.ui \
    CJanelaMenu.ui \
    CSimuladorPerdaTubulacao.ui \
    CSimuladorReologico.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
