QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CFluido.cpp \
    CGnuplot.cpp \
    CModeloBingham.cpp \
    CModeloNewtoniano.cpp \
    CModeloPotencia.cpp \
    CModeloReologico.cpp \
    CPoco.cpp \
    CRelatorioPoco.cpp \
    CSimuladorPocoHidroestatica.cpp \
    CSimuladorPocoTubos.cpp \
    CTrechoPoco.cpp \
    Main.cpp \
    janelaadicionarfluido.cpp \
    janelamenu.cpp \
    qcustomplot.cpp

HEADERS += \
    CFluido.h \
    CGnuplot.h \
    CModeloBingham.h \
    CModeloNewtoniano.h \
    CModeloPotencia.h \
    CModeloReologico.h \
    CPoco.h \
    CRelatorioPoco.h \
    CSimuladorPocoHidroestatica.h \
    CSimuladorPocoTubos.h \
    CTrechoPoco.h \
    janelaadicionarfluido.h \
    janelamenu.h \
    qcustomplot.h

FORMS += \
    CSimuladorPocoHidroestatica.ui \
    CSimuladorPocoTubos.ui \
    janelaadicionarfluido.ui \
    janelamenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
