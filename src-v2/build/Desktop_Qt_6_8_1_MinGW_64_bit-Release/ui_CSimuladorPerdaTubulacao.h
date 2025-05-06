/********************************************************************************
** Form generated from reading UI file 'CSimuladorPerdaTubulacao.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSIMULADORPERDATUBULACAO_H
#define UI_CSIMULADORPERDATUBULACAO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_CSimuladorPerdaTubulacao
{
public:
    QAction *actionArquivo_Dat;
    QWidget *centralwidget;
    QCustomPlot *customPlotPoco;
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *lbnTituloTemperaturaSuperiorFinal;
    QCheckBox *checkBoxPacker;
    QLineEdit *editTemperaturaSuperiorFinal;
    QLineEdit *editTemperaturaFundoInicial;
    QLineEdit *editNomePoco;
    QLineEdit *editProfundidadePacker;
    QLabel *lbnTituloTemperaturaFundoFinal;
    QSpacerItem *verticalSpacer;
    QPushButton *btnAtualizarDados;
    QSpacerItem *verticalSpacer_3;
    QLabel *lbnTituloConfiguraoInicial;
    QLineEdit *editTemperaturaSuperiorInicial;
    QLabel *lbnTituloProfundidadePacker;
    QLabel *lbnTituloNomePoco;
    QLabel *lbnTituloProfunidadeTotal;
    QLabel *lbnTituloConfiguraoFinal;
    QLabel *lbnTituloTemperaturaFundoInicial;
    QLabel *lbnTituloTemperaturaSuperiorInicial;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *editTemperaturaFundoFinal;
    QLineEdit *editProfundidadeTotal;
    QPushButton *btnAdicionarPropriedades;
    QLabel *lbnTituloPressaoSup;
    QLineEdit *editPressaoSup;
    QGroupBox *groupBox_3;
    QTabWidget *tabWidget_4;
    QWidget *tab_7;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QPushButton *btnAdicionarTrecho;
    QPushButton *btnRemoverTrecho;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tblTrechos;
    QWidget *tab_9;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *btnAdicionarFluido;
    QPushButton *btnRemoverFluido;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tblFluidos;
    QGroupBox *groupBox_4;
    QLabel *label_4;
    QTabWidget *tabWidget_5;
    QWidget *tab_10;
    QGroupBox *groupBox_2;
    QCustomPlot *customPlotTemperaturaInicial;
    QLabel *label_3;
    QWidget *tab_8;
    QGroupBox *groupBox_5;
    QCustomPlot *customPlotTemperaturaFinal;
    QLabel *label_8;
    QMenuBar *menubar;
    QMenu *menuArquivo;
    QMenu *menuImportar_Dados;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CSimuladorPerdaTubulacao)
    {
        if (CSimuladorPerdaTubulacao->objectName().isEmpty())
            CSimuladorPerdaTubulacao->setObjectName("CSimuladorPerdaTubulacao");
        CSimuladorPerdaTubulacao->resize(1444, 859);
        actionArquivo_Dat = new QAction(CSimuladorPerdaTubulacao);
        actionArquivo_Dat->setObjectName("actionArquivo_Dat");
        centralwidget = new QWidget(CSimuladorPerdaTubulacao);
        centralwidget->setObjectName("centralwidget");
        customPlotPoco = new QCustomPlot(centralwidget);
        customPlotPoco->setObjectName("customPlotPoco");
        customPlotPoco->setGeometry(QRect(1050, 40, 371, 761));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 301, 401));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        groupBox->setTitle(QString::fromUtf8(""));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 201, 16));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label->setFont(font);
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 30, 281, 360));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lbnTituloTemperaturaSuperiorFinal = new QLabel(gridLayoutWidget);
        lbnTituloTemperaturaSuperiorFinal->setObjectName("lbnTituloTemperaturaSuperiorFinal");
        QFont font1;
        font1.setBold(false);
        lbnTituloTemperaturaSuperiorFinal->setFont(font1);
        lbnTituloTemperaturaSuperiorFinal->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloTemperaturaSuperiorFinal, 10, 0, 1, 1);

        checkBoxPacker = new QCheckBox(gridLayoutWidget);
        checkBoxPacker->setObjectName("checkBoxPacker");
        checkBoxPacker->setFont(font1);

        gridLayout->addWidget(checkBoxPacker, 13, 0, 1, 3);

        editTemperaturaSuperiorFinal = new QLineEdit(gridLayoutWidget);
        editTemperaturaSuperiorFinal->setObjectName("editTemperaturaSuperiorFinal");

        gridLayout->addWidget(editTemperaturaSuperiorFinal, 10, 1, 1, 2);

        editTemperaturaFundoInicial = new QLineEdit(gridLayoutWidget);
        editTemperaturaFundoInicial->setObjectName("editTemperaturaFundoInicial");

        gridLayout->addWidget(editTemperaturaFundoInicial, 7, 1, 1, 2);

        editNomePoco = new QLineEdit(gridLayoutWidget);
        editNomePoco->setObjectName("editNomePoco");

        gridLayout->addWidget(editNomePoco, 0, 1, 1, 2);

        editProfundidadePacker = new QLineEdit(gridLayoutWidget);
        editProfundidadePacker->setObjectName("editProfundidadePacker");

        gridLayout->addWidget(editProfundidadePacker, 14, 1, 1, 2);

        lbnTituloTemperaturaFundoFinal = new QLabel(gridLayoutWidget);
        lbnTituloTemperaturaFundoFinal->setObjectName("lbnTituloTemperaturaFundoFinal");
        lbnTituloTemperaturaFundoFinal->setFont(font1);
        lbnTituloTemperaturaFundoFinal->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloTemperaturaFundoFinal, 11, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 0, 1, 3);

        btnAtualizarDados = new QPushButton(gridLayoutWidget);
        btnAtualizarDados->setObjectName("btnAtualizarDados");

        gridLayout->addWidget(btnAtualizarDados, 15, 1, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 12, 0, 1, 3);

        lbnTituloConfiguraoInicial = new QLabel(gridLayoutWidget);
        lbnTituloConfiguraoInicial->setObjectName("lbnTituloConfiguraoInicial");
        lbnTituloConfiguraoInicial->setFont(font1);
        lbnTituloConfiguraoInicial->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloConfiguraoInicial, 5, 0, 1, 3);

        editTemperaturaSuperiorInicial = new QLineEdit(gridLayoutWidget);
        editTemperaturaSuperiorInicial->setObjectName("editTemperaturaSuperiorInicial");

        gridLayout->addWidget(editTemperaturaSuperiorInicial, 6, 1, 1, 2);

        lbnTituloProfundidadePacker = new QLabel(gridLayoutWidget);
        lbnTituloProfundidadePacker->setObjectName("lbnTituloProfundidadePacker");
        lbnTituloProfundidadePacker->setFont(font1);
        lbnTituloProfundidadePacker->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloProfundidadePacker, 14, 0, 1, 1);

        lbnTituloNomePoco = new QLabel(gridLayoutWidget);
        lbnTituloNomePoco->setObjectName("lbnTituloNomePoco");
        lbnTituloNomePoco->setFont(font1);
        lbnTituloNomePoco->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloNomePoco, 0, 0, 1, 1);

        lbnTituloProfunidadeTotal = new QLabel(gridLayoutWidget);
        lbnTituloProfunidadeTotal->setObjectName("lbnTituloProfunidadeTotal");
        lbnTituloProfunidadeTotal->setFont(font1);
        lbnTituloProfunidadeTotal->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloProfunidadeTotal, 1, 0, 1, 1);

        lbnTituloConfiguraoFinal = new QLabel(gridLayoutWidget);
        lbnTituloConfiguraoFinal->setObjectName("lbnTituloConfiguraoFinal");
        lbnTituloConfiguraoFinal->setFont(font1);
        lbnTituloConfiguraoFinal->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloConfiguraoFinal, 9, 0, 1, 3);

        lbnTituloTemperaturaFundoInicial = new QLabel(gridLayoutWidget);
        lbnTituloTemperaturaFundoInicial->setObjectName("lbnTituloTemperaturaFundoInicial");
        lbnTituloTemperaturaFundoInicial->setFont(font1);
        lbnTituloTemperaturaFundoInicial->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloTemperaturaFundoInicial, 7, 0, 1, 1);

        lbnTituloTemperaturaSuperiorInicial = new QLabel(gridLayoutWidget);
        lbnTituloTemperaturaSuperiorInicial->setObjectName("lbnTituloTemperaturaSuperiorInicial");
        lbnTituloTemperaturaSuperiorInicial->setFont(font1);
        lbnTituloTemperaturaSuperiorInicial->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloTemperaturaSuperiorInicial, 6, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 3);

        editTemperaturaFundoFinal = new QLineEdit(gridLayoutWidget);
        editTemperaturaFundoFinal->setObjectName("editTemperaturaFundoFinal");

        gridLayout->addWidget(editTemperaturaFundoFinal, 11, 1, 1, 2);

        editProfundidadeTotal = new QLineEdit(gridLayoutWidget);
        editProfundidadeTotal->setObjectName("editProfundidadeTotal");

        gridLayout->addWidget(editProfundidadeTotal, 1, 1, 1, 2);

        btnAdicionarPropriedades = new QPushButton(gridLayoutWidget);
        btnAdicionarPropriedades->setObjectName("btnAdicionarPropriedades");

        gridLayout->addWidget(btnAdicionarPropriedades, 15, 0, 1, 1);

        lbnTituloPressaoSup = new QLabel(gridLayoutWidget);
        lbnTituloPressaoSup->setObjectName("lbnTituloPressaoSup");
        lbnTituloPressaoSup->setFont(font1);
        lbnTituloPressaoSup->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloPressaoSup, 2, 0, 1, 1);

        editPressaoSup = new QLineEdit(gridLayoutWidget);
        editPressaoSup->setObjectName("editPressaoSup");

        gridLayout->addWidget(editPressaoSup, 2, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 420, 1021, 391));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        tabWidget_4 = new QTabWidget(groupBox_3);
        tabWidget_4->setObjectName("tabWidget_4");
        tabWidget_4->setGeometry(QRect(10, 10, 1001, 371));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        tabWidget_4->setFont(font2);
        tabWidget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #eaeaea;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"}"));
        tabWidget_4->setIconSize(QSize(16, 16));
        tabWidget_4->setElideMode(Qt::TextElideMode::ElideNone);
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        gridLayoutWidget_3 = new QWidget(tab_7);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(10, 10, 981, 321));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        btnAdicionarTrecho = new QPushButton(gridLayoutWidget_3);
        btnAdicionarTrecho->setObjectName("btnAdicionarTrecho");

        gridLayout_3->addWidget(btnAdicionarTrecho, 1, 0, 1, 1);

        btnRemoverTrecho = new QPushButton(gridLayoutWidget_3);
        btnRemoverTrecho->setObjectName("btnRemoverTrecho");

        gridLayout_3->addWidget(btnRemoverTrecho, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        tblTrechos = new QTableWidget(gridLayoutWidget_3);
        if (tblTrechos->columnCount() < 9)
            tblTrechos->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tblTrechos->setObjectName("tblTrechos");
        tblTrechos->setAutoScrollMargin(16);
        tblTrechos->horizontalHeader()->setMinimumSectionSize(37);
        tblTrechos->horizontalHeader()->setDefaultSectionSize(126);
        tblTrechos->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));

        gridLayout_3->addWidget(tblTrechos, 0, 0, 1, 3);

        tabWidget_4->addTab(tab_7, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        gridLayoutWidget_2 = new QWidget(tab_9);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(0, 10, 921, 321));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnAdicionarFluido = new QPushButton(gridLayoutWidget_2);
        btnAdicionarFluido->setObjectName("btnAdicionarFluido");

        gridLayout_2->addWidget(btnAdicionarFluido, 1, 0, 1, 1);

        btnRemoverFluido = new QPushButton(gridLayoutWidget_2);
        btnRemoverFluido->setObjectName("btnRemoverFluido");

        gridLayout_2->addWidget(btnRemoverFluido, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        tblFluidos = new QTableWidget(gridLayoutWidget_2);
        if (tblFluidos->columnCount() < 5)
            tblFluidos->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font1);
        tblFluidos->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font1);
        tblFluidos->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font1);
        tblFluidos->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font1);
        tblFluidos->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font1);
        tblFluidos->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        tblFluidos->setObjectName("tblFluidos");
        tblFluidos->horizontalHeader()->setDefaultSectionSize(153);

        gridLayout_2->addWidget(tblFluidos, 0, 0, 1, 3);

        tabWidget_4->addTab(tab_9, QString());
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(1040, 10, 391, 801));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        groupBox_4->setTitle(QString::fromUtf8(""));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 10, 201, 16));
        label_4->setFont(font);
        tabWidget_5 = new QTabWidget(centralwidget);
        tabWidget_5->setObjectName("tabWidget_5");
        tabWidget_5->setGeometry(QRect(630, 10, 401, 361));
        tabWidget_5->setFont(font2);
        tabWidget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #eaeaea;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"}"));
        tabWidget_5->setIconSize(QSize(16, 16));
        tabWidget_5->setElideMode(Qt::TextElideMode::ElideNone);
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        groupBox_2 = new QGroupBox(tab_10);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 10, 381, 311));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        groupBox_2->setTitle(QString::fromUtf8(""));
        customPlotTemperaturaInicial = new QCustomPlot(groupBox_2);
        customPlotTemperaturaInicial->setObjectName("customPlotTemperaturaInicial");
        customPlotTemperaturaInicial->setGeometry(QRect(10, 20, 371, 291));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 0, 211, 16));
        label_3->setFont(font);
        tabWidget_5->addTab(tab_10, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        groupBox_5 = new QGroupBox(tab_8);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(0, 0, 381, 321));
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        groupBox_5->setTitle(QString::fromUtf8(""));
        customPlotTemperaturaFinal = new QCustomPlot(groupBox_5);
        customPlotTemperaturaFinal->setObjectName("customPlotTemperaturaFinal");
        customPlotTemperaturaFinal->setGeometry(QRect(10, 30, 371, 291));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 10, 211, 16));
        label_8->setFont(font);
        tabWidget_5->addTab(tab_8, QString());
        CSimuladorPerdaTubulacao->setCentralWidget(centralwidget);
        groupBox_4->raise();
        customPlotPoco->raise();
        groupBox->raise();
        groupBox_3->raise();
        tabWidget_5->raise();
        menubar = new QMenuBar(CSimuladorPerdaTubulacao);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1444, 22));
        menuArquivo = new QMenu(menubar);
        menuArquivo->setObjectName("menuArquivo");
        menuImportar_Dados = new QMenu(menuArquivo);
        menuImportar_Dados->setObjectName("menuImportar_Dados");
        CSimuladorPerdaTubulacao->setMenuBar(menubar);
        statusbar = new QStatusBar(CSimuladorPerdaTubulacao);
        statusbar->setObjectName("statusbar");
        CSimuladorPerdaTubulacao->setStatusBar(statusbar);
        QWidget::setTabOrder(editNomePoco, editProfundidadeTotal);
        QWidget::setTabOrder(editProfundidadeTotal, editTemperaturaSuperiorInicial);
        QWidget::setTabOrder(editTemperaturaSuperiorInicial, editTemperaturaFundoInicial);
        QWidget::setTabOrder(editTemperaturaFundoInicial, editTemperaturaSuperiorFinal);
        QWidget::setTabOrder(editTemperaturaSuperiorFinal, editTemperaturaFundoFinal);
        QWidget::setTabOrder(editTemperaturaFundoFinal, checkBoxPacker);
        QWidget::setTabOrder(checkBoxPacker, editProfundidadePacker);
        QWidget::setTabOrder(editProfundidadePacker, btnAdicionarPropriedades);
        QWidget::setTabOrder(btnAdicionarPropriedades, btnAtualizarDados);
        QWidget::setTabOrder(btnAtualizarDados, tabWidget_4);
        QWidget::setTabOrder(tabWidget_4, btnAdicionarFluido);
        QWidget::setTabOrder(btnAdicionarFluido, btnRemoverFluido);
        QWidget::setTabOrder(btnRemoverFluido, tblFluidos);
        QWidget::setTabOrder(tblFluidos, btnAdicionarTrecho);
        QWidget::setTabOrder(btnAdicionarTrecho, btnRemoverTrecho);
        QWidget::setTabOrder(btnRemoverTrecho, tblTrechos);
        QWidget::setTabOrder(tblTrechos, tabWidget_5);

        menubar->addAction(menuArquivo->menuAction());
        menuArquivo->addAction(menuImportar_Dados->menuAction());
        menuImportar_Dados->addAction(actionArquivo_Dat);

        retranslateUi(CSimuladorPerdaTubulacao);

        tabWidget_4->setCurrentIndex(0);
        tabWidget_5->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CSimuladorPerdaTubulacao);
    } // setupUi

    void retranslateUi(QMainWindow *CSimuladorPerdaTubulacao)
    {
        CSimuladorPerdaTubulacao->setWindowTitle(QCoreApplication::translate("CSimuladorPerdaTubulacao", "MainWindow", nullptr));
        actionArquivo_Dat->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Arquivo (.Dat)", nullptr));
        label->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Dados do Po\303\247o", nullptr));
        lbnTituloTemperaturaSuperiorFinal->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Temperatura de Superfice (\302\272F)", nullptr));
        checkBoxPacker->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "H\303\241 packer?", nullptr));
        lbnTituloTemperaturaFundoFinal->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Temperatura de Fundo (\302\272F)", nullptr));
        btnAtualizarDados->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Atualizar Dados", nullptr));
        lbnTituloConfiguraoInicial->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Configura\303\247\303\243o Inicial", nullptr));
        lbnTituloProfundidadePacker->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Profundidade do Packer (ft)", nullptr));
        lbnTituloNomePoco->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Nome Po\303\247o", nullptr));
        lbnTituloProfunidadeTotal->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Profundidade Total (ft)", nullptr));
        lbnTituloConfiguraoFinal->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Configura\303\247\303\243o Final", nullptr));
        lbnTituloTemperaturaFundoInicial->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Temperatura de Fundo (\302\272F)", nullptr));
        lbnTituloTemperaturaSuperiorInicial->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Temperatura de Superfice (\302\272F)", nullptr));
        btnAdicionarPropriedades->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Adicionar Propriedade", nullptr));
        lbnTituloPressaoSup->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Press\303\243o na Superficie (psi)", nullptr));
        groupBox_3->setTitle(QString());
        btnAdicionarTrecho->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Adicionar Trecho", nullptr));
        btnRemoverTrecho->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Remover Trecho", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblTrechos->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Trecho", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblTrechos->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Prof. Inicial (ft)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblTrechos->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Prof. Final (ft)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblTrechos->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Diam. Externo (in)", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblTrechos->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Diam Interno (in)", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblTrechos->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Coef. Poisson", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblTrechos->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Coef. Exp. T\303\251rm. (1/F)", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblTrechos->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "M\303\263d. Elast. (psi)", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblTrechos->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Peso/unid. (lb/ft)", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_7), QCoreApplication::translate("CSimuladorPerdaTubulacao", "           Dados das Se\303\247\303\265es           ", nullptr));
        btnAdicionarFluido->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Adicionar Fluido", nullptr));
        btnRemoverFluido->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Remover Fluido", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblFluidos->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Nome", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblFluidos->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Densidade (lbm/gal)", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblFluidos->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Viscosidade (cP)", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblFluidos->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Prof. Inicial (ft)", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblFluidos->horizontalHeaderItem(4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Prof. Final (ft)", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_9), QCoreApplication::translate("CSimuladorPerdaTubulacao", "           Dados dos Fluidos            ", nullptr));
        label_4->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Esquema do Po\303\247o", nullptr));
        label_3->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Profundidade x Temperatura", nullptr));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_10), QCoreApplication::translate("CSimuladorPerdaTubulacao", "           Condi\303\247\303\265es Iniciais           ", nullptr));
        label_8->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Profundidade x Temperatura", nullptr));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_8), QCoreApplication::translate("CSimuladorPerdaTubulacao", "           Condi\303\247\303\265es Finais           ", nullptr));
        menuArquivo->setTitle(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Arquivo", nullptr));
        menuImportar_Dados->setTitle(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Importar Dados", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSimuladorPerdaTubulacao: public Ui_CSimuladorPerdaTubulacao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSIMULADORPERDATUBULACAO_H
