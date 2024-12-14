QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CFluido.cpp \
    CModeloBingham.cpp \
    CModeloNewtoniano.cpp \
    CModeloPotencia.cpp \
    CModeloReologico.cpp \
    CPoco.cpp \
    CTrechoPoco.cpp \
    janelaadicionarfluido.cpp \
    janelapressaohidroestatica.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    CFluido.h \
    CModeloBingham.h \
    CModeloNewtoniano.h \
    CModeloPotencia.h \
    CModeloReologico.h \
    CPoco.h \
    CTrechoPoco.h \
    janelaadicionarfluido.h \
    janelapressaohidroestatica.h \
    mainwindow.h

FORMS += \
    janelaadicionarfluido.ui \
    janelapressaohidroestatica.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
